set GRAPHVIZ=D:\mobileFX\Projects\Software\Coconut\IDE\Studio\etc\3rd_party\graphviz\bin
set DIAGRAMS=D:\mobileFX\Projects\Software\Coconut\Projects\Coco.project\.SDK\Documentation\ClassDiagrams
"%GRAPHVIZ%\dot.exe" -Kfdp -Tsvg  -o"%DIAGRAMS%\ClassDiagram.svg" "%DIAGRAMS%\ClassDiagram.gv"
"%GRAPHVIZ%\dot.exe" -Kfdp -Tpdf  -o"%DIAGRAMS%\ClassDiagram.pdf" "%DIAGRAMS%\ClassDiagram.gv"
