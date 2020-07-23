apr22018

THIS IS  THE EASIEST and QUICKEST  solution for PRINTING .pdf  file AS
TEXT in ONE Column, see ../okular/README.okular

Thus ignore the rest of this file, notes from 8feb2018.



8feb2018

* 'pdf2text yamauchi.pdf' doesn't crate a proper yamauchi.txt, where
  text interlived by columns, thus not readable.

* pdf2text -layout yamauchi.txt > yamauchi.-layout.txt, is readable
  but does not allow cut and paste for just one column at a time.

* thus extract from yamauchi.-layout.txt the first 1-70
  characters===column1 into one file.  and extract from 71-EOF
  characters==column2 into another file ie yamauchi.-layout.c1-70.txt
  and yamauchi.-layout.c71-.txt

* merge 'manually' column1 and column2 files is required, with text
  reading into one column, in order, only, resulting in
  yamauchi.col1col2merged.txt


* PRODUCTIVITY caviet, adhere to during semester with so little time
  to do assignment.:
  
  Since pdf2text was getting difficult to attain a proper .txt file
  and certianly by the time the seperate cut files are created and the
  realisation is made that the seperate cut files need to be merged by
  hand still into one column, into another text file, which could take
  many housrs, you probably should abandon the merging and make notes
  of the document by hand.  Especially you only need to read a few
  sections of the document(eg adstract, conclusion, intro, frontier
  detection).

  This merging into one file/column is required if you want to cut and
  paste from the document to a summary file directly.  Not worth it
  given the time it takes to get into one column.
  
  If you print the to documents containing column1 and column2
  seperatly you can read the document but it is difficult to read in
  the right order.  So again it probably would be quicker to just make
  my summary notes for documents by hand.

  SUMMARY: When you come accross a scanned paper or document just
  summarise the text by hand into a text file.  As getting the
  document text into a one column text file takes too much time.  The
  one column text file is required if you want to do a direct copy and
  paste to a summary txt file.  If you don't need to do a direct copy
  and past into a summary txt file, great, just summarise document in
  a text file by hand.
  
  Do NOT print these documents as you just get a solid black
  page which uses up a lot of toner.
  
