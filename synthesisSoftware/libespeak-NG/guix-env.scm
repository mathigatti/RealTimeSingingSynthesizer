;; guix package --install-from-file=guix-env.scm
;; or
;; guix build -f guix-env.scm

;;; modules
(use-modules
 (ice-9 popen)
 (ice-9 match)
 (ice-9 rdelim)
 (guix packages)
 (guix build-system gnu)
 (guix gexp)
 ((guix build utils) #:select (with-directory-excursion))
 (guix git-download)
 (guix licenses)
 (guix utils)
 (gnu packages)
 (gnu packages python)
 (gnu packages pkg-config)
 (gnu packages autotools)
 (gnu packages gettext)
 (gnu packages base)
 ((guix licenses) #:prefix license:))

;;; local source dir
(define %source-dir (dirname (current-filename)))

;; package
(define ecantorix-sg
  (package
    (name "ecantorix-sg")
    (version "git09022017")
    (source
     (local-file %source-dir
                 #:recursive? #t
                 #:select? (git-predicate %source-dir)))
    (build-system gnu-build-system)
    (arguments '(#:configure-flags '("--enable-silent-rules")))
    (inputs `(
       ("python-3.5" ,python-3.5)
    )) ;; end of inputs
    (native-inputs
     `(("pkg-config" ,pkg-config)
       ("autoconf" ,autoconf)
       ("automake" ,automake)
       ("gnu-gettext" ,gnu-gettext)
       ("libtool" ,libtool)
       ("which" ,which)
    ))
    ;; call autogen.sh before ./configure
    (arguments '(
    #:parallel-build? #f
    #:tests? #f
    #:make-flags (list (string-append "PREFIX=" (assoc-ref %outputs "out"))
                          (string-append "DATADIR="
                                         (assoc-ref %outputs "out")
                                         "/share/ecantorix-sg-data")
                          (string-append "LDFLAGS=-Wl,-rpath="
                                         (assoc-ref %outputs "out")
                                         "/lib")
                          )
    #:phases (modify-phases %standard-phases (add-after 'unpack 'bootstrap (lambda _ (zero? (system* "sh" "autogen.sh"))))) ; call autogen.sh before ./configure
    )) ; end of arguments block
    
    
    
    (synopsis "Clone of the Yamaha PLG100-SG singing formant synthesizer")
    (description "ECantorix SG is fork of espeak-ng that supports singing in 99 languages including Japanese, English and Swedish.")
    (home-page "https://notabug.org/isengaara/ecantorix-sinsy-ng")
    (license gpl3+)))
    

ecantorix-sg
