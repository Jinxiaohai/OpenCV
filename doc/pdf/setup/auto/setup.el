(TeX-add-style-hook
 "setup"
 (lambda ()
   (TeX-add-to-alist 'LaTeX-provided-package-options
                     '(("xcolor" "table") ("geometry" "paperwidth=185mm" "paperheight=260mm" "text={148mm,220mm}" "left=21mm" "right=21mm" "top=25.5mm") ("hyperref" "colorlinks" "citecolor=blue" "linkcolor=seagreen" "pagebackref") ("lineno" "displaymath" "left")))
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "path")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "url")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "nolinkurl")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "hyperbaseurl")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "hyperimage")
   (add-to-list 'LaTeX-verbatim-macros-with-braces-local "hyperref")
   (add-to-list 'LaTeX-verbatim-macros-with-delims-local "path")
   (TeX-run-style-hooks
    "ctex"
    "xcolor"
    "fancyhdr"
    "geometry"
    "titlesec"
    "titletoc"
    "indentfirst"
    "hyperref"
    "wallpaper"
    "draftwatermark"
    "lineno"
    "rotating"
    "graphicx"
    "multirow"
    "amsmath")
   (LaTeX-add-xcolor-definecolors
    "seagreen"))
 :latex)

