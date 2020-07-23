
(cl:in-package :asdf)

(defsystem "voice_node-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "voice_node" :depends-on ("_package_voice_node"))
    (:file "_package_voice_node" :depends-on ("_package"))
  ))