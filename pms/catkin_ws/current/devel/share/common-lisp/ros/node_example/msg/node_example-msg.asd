
(cl:in-package :asdf)

(defsystem "node_example-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "NodeExampleData" :depends-on ("_package_NodeExampleData"))
    (:file "_package_NodeExampleData" :depends-on ("_package"))
  ))