
EXTRA_DIST = #DSILI-code.tex \
#	figures/associationsbi.eps \
#	figures/associations-instancetypes.eps \
#	figures/channel.eps \
#	figures/channelrti.eps \
#	figures/diag_atom.eps \
#	figures/fig-extrapolate.eps \
#	figures/gui-020.eps \
#	figures/network-bridge.eps \
#	figures/network-facade.eps \
#	figures/network-interposer.eps \
#	figures/network-probe.eps \
#	figures/network-telegraph.eps \
#	figures/network-testharness.eps \
#	figures/network-transformer.eps \
#	figures/new-package-org.eps \
#	figures/overview-activity-action.eps \
#	figures/overview-class-action.eps \
#	figures/overview-class-actionhandler.eps \
#	figures/overview-class-handler.eps \
#	figures/overview-class-interceptor.eps \
#	figures/overview-class-pluginclasses.eps \
#	figures/overview-class-plugin.eps \
#	figures/overview-class-profile.eps \
#	figures/overview-class-uniqueid.eps \
#	figures/overview-collaboration-action.eps \
#	figures/overview-sequence-action.eps \
#	figures/packages.eps \
#	figures/simplicity-helloworld.eps \
#	figures/sol-gateway.eps \
#	figures/sol-library.eps \
#	figures/sol-middleware.eps \
#	figures/sol-rewrite.eps \
#	figures/superhandler2.eps \
#	figures/superhandler.eps \
#	figures/superhandler-rev.eps \
#	figures/table-uniqueid.eps \
#	composite_identifier_basictable.tex \
#	DSILI-demo.tex \
#	rcs-doc.sty \
#	rcs.sty \
#	dsili.dtd \
#	DSTOvert.ps \
#	dstodoc.cls \
#	dsto11.clo

docdir=$(prefix)/doc

doc_DATA = #DSILI-code.ps DSILI-code.pdf \
#		DSILI-demo.ps DSILI-demo.pdf \
#		DSILI-feature-overview.ps DSILI-feature-overview.pdf \
#		DSILI-coverage.ps DSILI-coverage.pdf \
#		DSILI-future-dir.ps DSILI-future-dir.pdf \
#		DSILI-xml-file-format.ps DSILI-xml-file-format.pdf

%.pdf: %.ps
	ps2pdf $*.ps

%.ps: %.tex %.dvi
	dvips -o -t a4 $*

%.dvi: %.tex
	latex $*
	latex $*
	latex $*
