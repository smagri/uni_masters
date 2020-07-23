--- ../ass3wrks/preDataFusion/dataFusion.cpp	2017-10-18 18:09:15.454223669 +1100
+++ ./dataFusion.cpp	2017-11-01 19:15:33.689975564 +1100
@@ -17,7 +17,13 @@
   // Default contructor,  expected to be called  after constructors of
   // classes that derive from the DataFusion class are executed.
 
-  
+  // Set default fusion method if user doesn't specify.
+  //
+  // method1: fusionMethod_ = "min";
+  // OR
+  // method2:
+  setFusionMethod("min");
+    
 }
 
 
@@ -222,7 +228,7 @@
   
   while(true){
     // Aquire the mutex locks and process the buffers/FIFO's/Que's of
-    // all the sensor.
+    // all the sensors.
 
 
     for (i=0; i<rangers_.size(); i++){
@@ -293,6 +299,9 @@
 		  dataBuff[rangerNum].buffQue_.front());
 
 	  // Extrapolate next sample.
+	  //
+	  // Should this be:
+	  //	x = x2 + ((1.0 / samplingRate) / 2)
 	  samplingRate = rangers_.at(rangerNum)->getHdwFixedSamplingRate();
 	  x = x2 + (1.0 / samplingRate);
 	  
