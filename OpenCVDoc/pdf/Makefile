EXE=OpenCV.pdf
SRC=OpenCV.tex
BIB=OpenCV.aux

$(EXE):$(SRC)
	xelatex $(SRC)

.PHONY.:look
look:
	evince OpenCV.pdf

.PHONY.:clean
clean:
	$(RM) OpenCV.aux OpenCV.log OpenCV.pdf OpenCV.dvi OpenCV.bbl OpenCV.blg OpenCV.toc OpenCV.out OpenCV.nav OpenCV.snm OpenCV.thm OpenCV.lot OpenCV.lof
