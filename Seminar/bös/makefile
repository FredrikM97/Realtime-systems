doc:
	sed 's/bös\///g' ../doc.md | pandoc \
	-V date=`date '+%F'` \
	--filter pandoc-citeproc --bibliography=refs.bib --csl elsevier-vancouver.csl \
	-o ../doc.pdf

pres:
	sed 's/bös\///g' ../pres.md | pandoc -t beamer -o ../pres.pdf

pres_debug:
	sed 's/bös\///g' ../pres.md | pandoc --verbose -t beamer -o ../pres.pdf