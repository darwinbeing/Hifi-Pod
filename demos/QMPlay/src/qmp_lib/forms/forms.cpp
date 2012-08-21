#include "var.h"

#include "save.h"
#include "thread.h"

#include "miniQMP.cpp"
#include "formDockCh.cpp"
#include "formDownload.cpp"
#include "formCp.cpp"
#include "formProp.cpp"
#include "formLang.cpp"
#include "formStyle.cpp"
#include "formFunc.cpp"
#include "formPlaylist.cpp"
#include "formSetup.cpp"
#include "formAbout.cpp"
#include "formSL.cpp"
#include "form1.cpp"

Form1::Form1(QWidget *parent):QMainWindow(parent)
{
	ui.setupUi(this);
	canChSignal = volFromMiniQMP = volSettings = cf1 = false;
}
FormSetup::FormSetup(QWidget *parent):QWidget(parent)
{
	ui.setupUi(this);
	reloadPlugins = false;
}
FormPlaylist::FormPlaylist(QWidget *parent):QWidget(parent)
{
	ui.setupUi(this);
}
FormFunc::FormFunc(QWidget *parent):QWidget(parent)
{
	ui.setupUi(this);
}
FormSL::FormSL(QWidget *parent):QWidget(parent)
{
	ui.setupUi(this);
}
FormStyle::FormStyle(QWidget *parent):QWidget(parent)
{
	ui.setupUi(this);
}
FormLang::FormLang(QWidget *parent):QWidget(parent)
{
	ui.setupUi(this);
}
FormAbout::FormAbout(QWidget *parent):QWidget(parent)
{
	ui.setupUi(this);
}
FormProp::FormProp(QWidget *parent):QWidget(parent)
{
	ui.setupUi(this);
}
FormCp::FormCp(QWidget *parent):QWidget(parent)
{
	ui.setupUi(this);
}
FormDock::FormDock(QWidget *parent):QWidget(parent)
{
	ui.setupUi(this);
}
FormDownload::FormDownload(QWidget *parent):QWidget(parent)
{
	ui.setupUi(this);
	connect( &timDwn, SIGNAL( timeout() ), this, SLOT( timDwnDo() ) );
}
miniQmp::miniQmp(QWidget *parent):QFrame(parent)
{
	ui.setupUi(this);
	dockVis = closed = false;
}
musicInfo::musicInfo(QWidget *parent):QFrame(parent)
{
	ui.setupUi(this);
}

void connecty()
{
//Form1
	qApp->connect(f1.ui.playButton, SIGNAL(clicked()), &f1, SLOT(play()));
	qApp->connect(f1.ui.dodatkiB, SIGNAL(clicked()), &f1, SLOT(funkcje_opn()));
	qApp->connect(f1.ui.stopButton, SIGNAL(clicked()), &f1, SLOT(stop()));
	qApp->connect(f1.ui.actionMuzyka, SIGNAL(triggered(bool)), &fp, SLOT(loadmus_File()));
	qApp->connect(f1.ui.actionZakoncz, SIGNAL(triggered(bool)), &f1, SLOT(quit()));
	qApp->connect(f1.ui.pauseButton, SIGNAL(clicked()), &f1, SLOT(BTpause()));
	qApp->connect(f1.ui.nextButton, SIGNAL(clicked()), &f1, SLOT(nextB()));
	qApp->connect(f1.ui.prevButton, SIGNAL(clicked()), &f1, SLOT(prevB()));
	qApp->connect(f1.ui.actionOpcje, SIGNAL(triggered(bool)), &f1, SLOT(opcje()));
	qApp->connect(f1.ui.opcjeButton, SIGNAL(clicked()), &f1, SLOT(opcje()));
	qApp->connect(f1.ui.playlistButton, SIGNAL(clicked()), &f1, SLOT(showplaylist()));
	qApp->connect(f1.ui.actionSHPlist, SIGNAL(triggered(bool)), &f1, SLOT(showplaylist()));
	qApp->connect(f1.ui.actionClrplist, SIGNAL(triggered(bool)), &fp, SLOT(clrplist()));
	qApp->connect(f1.ui.actionPlay, SIGNAL(triggered(bool)), &f1, SLOT(play()));
	qApp->connect(f1.ui.actionStop, SIGNAL(triggered(bool)), &f1, SLOT(stop()));
	qApp->connect(f1.ui.actionPause, SIGNAL(triggered(bool)), &f1, SLOT(BTpause()));
	qApp->connect(f1.ui.actionNext, SIGNAL(triggered(bool)), &f1, SLOT(nextB()));
	qApp->connect(f1.ui.actionPrevious, SIGNAL(triggered(bool)), &f1, SLOT(prevB()));
	qApp->connect(f1.ui.actionInformacje, SIGNAL(triggered(bool)), &f1, SLOT(musinfo()));
	qApp->connect(&timref, SIGNAL(timeout()), &f1, SLOT(timrefDo()));
	qApp->connect(f1.ui.act_funkcje, SIGNAL(triggered(bool)), &f1, SLOT(funkcje_opn()));
	qApp->connect(f1.ui.actionInformacje_2, SIGNAL(triggered(bool)), &f1, SLOT(info()));
	qApp->connect(f1.ui.aWAV, SIGNAL(triggered(bool)), &f1, SLOT(aWAV()));
	qApp->connect(f1.ui.musicPos, SIGNAL(actionTriggered(int)), &f1, SLOT(slAT(int)));
	qApp->connect(f1.ui.musicPos, SIGNAL(sliderReleased()), &f1, SLOT(slR()));
	qApp->connect(f1.ui.musicPos, SIGNAL(sliderPressed()), &f1, SLOT(slP()));
	qApp->connect(f1.ui.volLS, SIGNAL(valueChanged(int)), &f1, SLOT(setVol(int)));
	qApp->connect(f1.ui.volRS, SIGNAL(valueChanged(int)), &f1, SLOT(setVol(int)));
	qApp->connect(f1.ui.a_savMus, SIGNAL(triggered(bool)), &f1, SLOT(savMus()));
	qApp->connect(f1.ui.actionBrak, SIGNAL(triggered(bool)), &fp, SLOT(pu0()));
	qApp->connect(f1.ui.actionLosowo, SIGNAL(triggered(bool)), &fp, SLOT(pu1()));
	qApp->connect(f1.ui.actionPowtarzanie_utworu, SIGNAL(triggered(bool)), &fp, SLOT(pu2()));
	qApp->connect(f1.ui.actionPowtarzanie_listy, SIGNAL(triggered(bool)), &fp, SLOT(pu3()));
	qApp->connect(f1.ui.actionDo_ty_u, SIGNAL(triggered(bool)), &fp, SLOT(pu4()));
	qApp->connect(f1.ui.actionPlaylista, SIGNAL(triggered(bool)), &fp, SLOT(odczytajB()));
	qApp->connect(f1.ui.actionPlaylista_2, SIGNAL(triggered(bool)), &fp, SLOT(zapiszB()));
	qApp->connect(f1.ui.actionAB, SIGNAL(triggered(bool)), &f1, SLOT(AboutQMP()));
	qApp->connect(f1.ui.actionWyszukaj, SIGNAL(triggered(bool)), &fp, SLOT(focusSearchBar()));
	qApp->connect(f1.ui.NewPLAct, SIGNAL(triggered(bool)), &fp, SLOT(newPL()));
	qApp->connect(f1.ui.nextXs, SIGNAL(triggered(bool)), &f1, SLOT(NextXs()));
	qApp->connect(f1.ui.pwp_a, SIGNAL(triggered(bool)), &f1, SLOT(pwp()));
	qApp->connect(f1.ui.pwl_a, SIGNAL(triggered(bool)), &f1, SLOT(pwl()));
	qApp->connect(f1.ui.vup_a, SIGNAL(triggered(bool)), &f1, SLOT(volup()));
	qApp->connect(f1.ui.vdwn_a, SIGNAL(triggered(bool)), &f1, SLOT(voldown()));
	qApp->connect(f1.ui.wlasciwosciA, SIGNAL(triggered(bool)), &fp, SLOT(wlasciwosci()));
	qApp->connect(f1.ui.netA, SIGNAL(triggered(bool)), &f1, SLOT(netA()));
	qApp->connect(f1.ui.selMusA, SIGNAL(triggered(bool)), &f1, SLOT(selA()));
	qApp->connect( &tray, SIGNAL( activated(QSystemTrayIcon::ActivationReason) ),&f1,SLOT( mnuAct(QSystemTrayIcon::ActivationReason) ) );
	qApp->connect(f1.ui.ukryjA, SIGNAL(triggered(bool)), &f1, SLOT(SoH()));
	qApp->connect(f1.ui.delWpisyA, SIGNAL(triggered(bool)), &fp, SLOT(delWpis()));
	qApp->connect(f1.ui.actionZa_aduj, SIGNAL(triggered(bool)), &fp, SLOT(loadPL()));
	qApp->connect(f1.ui.actionZapisz, SIGNAL(triggered(bool)), &fp, SLOT(savePL()));
	qApp->connect(f1.ui.actionZmie_nazw, SIGNAL(triggered(bool)), &fp, SLOT(renameList()));
	qApp->connect(f1.ui.actionDodaj_list, SIGNAL(triggered(bool)), &fp, SLOT(loadlist()));
	qApp->connect(f1.ui.actionUsu_list, SIGNAL(triggered(bool)), &fp, SLOT(dellist()));
	qApp->connect(f1.ui.actionCzy_listy, SIGNAL(triggered(bool)), &fp, SLOT(clrlist()));
	qApp->connect(f1.ui.sizeA, SIGNAL(triggered(bool)), &fp, SLOT(sizeB()));
	qApp->connect(f1.ui.QMPB, SIGNAL(clicked()), &f1, SLOT(AboutQMP()));
	qApp->connect(f1.ui.updatesA, SIGNAL(triggered(bool)), &f1, SLOT(checkUpdatesButton()));
	qApp->connect(&timQVis, SIGNAL(timeout()), &f1, SLOT(updateQVis()));
	qApp->connect(f1.ui.nlistA, SIGNAL(triggered(bool)), &fp, SLOT(nextPL()));
	qApp->connect(f1.ui.plistA, SIGNAL(triggered(bool)), &fp, SLOT(prevPL()));
	qApp->connect(f1.ui.eqB, SIGNAL(clicked()), &f1, SLOT(showEq()));
	qApp->connect(f1.ui.actionAbout_Qt, SIGNAL(triggered(bool)), qApp, SLOT(aboutQt()));
	qApp->connect(f1.ui.volLS, SIGNAL(customContextMenuRequested(QPoint)), &f1, SLOT(volMnu()));
	qApp->connect(f1.ui.volRS, SIGNAL(customContextMenuRequested(QPoint)), &f1, SLOT(volMnu()));
	qApp->connect(f1.ui.actionOd_wie, SIGNAL(triggered(bool)), &fp, SLOT(listRef()));
	qApp->connect(f1.ui.actionZatrzymaj, SIGNAL(triggered(bool)), &fp, SLOT(stopLoading()));
	qApp->connect(f1.ui.playlistButton, SIGNAL(customContextMenuRequested(QPoint)), &fp, SLOT(_mnuPlistWindow()));
	qApp->connect(f1.ui.infoB, SIGNAL(clicked()), &f1, SLOT(musinfo()));
	qApp->connect(f1.ui.actionDir, SIGNAL(triggered(bool)), &fp , SLOT( loadmus_Dir() ));
	qApp->connect(&tray, SIGNAL( messageClicked() ),&f1,SLOT( TrayMessageClicked() ));
	qApp->connect(f1.ui.actionKopiuj, SIGNAL( triggered(bool) ),&fp,SLOT(kopiuj()));
	qApp->connect(f1.ui.actionWklej, SIGNAL( triggered(bool) ),&fp,SLOT(wklej()));
	qApp->connect(f1.ui.actionZaznacz, SIGNAL( triggered(bool) ),&fp,SLOT(sel()));
	qApp->connect(f1.ui.actionOdznacz, SIGNAL( triggered(bool) ),&fp,SLOT(unsel()));
	qApp->connect(f1.ui.opcjeButton, SIGNAL(customContextMenuRequested(QPoint)), &f1, SLOT(showMnuOpt()));
	qApp->connect(f1.ui.miniVersionB, SIGNAL( clicked() ),&f1,SLOT(miniVersion()));
	qApp->connect(f1.ui.actionSortMod, SIGNAL( triggered(bool) ),&fp,SLOT(sortMod()));
	qApp->connect(f1.ui.actionSortTitle, SIGNAL( triggered(bool) ),&fp,SLOT(sortTitle()));
	qApp->connect(f1.ui.actionSortLength, SIGNAL( triggered(bool) ),&fp,SLOT(sortLength()));
	qApp->connect(f1.ui.copyTitleA, SIGNAL( triggered(bool) ),&f1,SLOT(copyTitleA()));
	qApp->connect(f1.ui.actionSortRandom, SIGNAL( triggered(bool) ),&fp,SLOT(sortRandom()));

//FormPlaylist
	fp.ui.addButton->setMenu( &menuAdd );
	fp.ui.actButton->setMenu( &menuPlistAct );
	fp.ui.searchModeB->setMenu( &mnuSearch );
	qApp->connect(titlelist, SIGNAL( itemDoubleClicked(QListWidgetItem*) ), &f1, SLOT( play() ));
	qApp->connect(fp.ui.clrButton, SIGNAL(clicked()), &fp, SLOT(clrplist()));
	qApp->connect(fp.ui.delButton, SIGNAL(clicked()), &fp, SLOT(delWpis()));
	qApp->connect(&plistthr, SIGNAL(finished()), &fp, SLOT(plistthrFinished()));
	qApp->connect(fp.ui.listPlaylstBox, SIGNAL(clicked()), &fp, SLOT(_listPlaylst()));
	qApp->connect(fp.ui.todownButton, SIGNAL(clicked()), &fp, SLOT(toDown()));
	qApp->connect(fp.ui.toupButton, SIGNAL(clicked()), &fp, SLOT(toUp()));
	qApp->connect(fp.ui.listPlaylst, SIGNAL(customContextMenuRequested(QPoint)), &fp, SLOT(plistlstMenu()));
	qApp->connect(titlelist, SIGNAL(customContextMenuRequested(QPoint)), &fp, SLOT(titlelstMenu()));
	qApp->connect(fp.ui.odczytajB, SIGNAL(clicked()), &fp, SLOT(odczytajB()));
	qApp->connect(fp.ui.zapiszB, SIGNAL(clicked()), &fp, SLOT(zapiszB()));
	qApp->connect(fp.ui.listPlaylst, SIGNAL( itemDoubleClicked(QListWidgetItem*) ), &fp, SLOT( loadPL() ));
	qApp->connect(&fp, SIGNAL( plistTimeTextChanged(QString) ), &fp, SLOT( chPlistTimeText(QString) ));
	qApp->connect(&fp, SIGNAL( itemTextChanged(int,QString) ), &fp, SLOT( chItemText(int,QString) ));
	qApp->connect(&fp, SIGNAL( addingLTextChanged(QString) ), &fp, SLOT( chAddingLText(QString) ));
	qApp->connect(fp.ui.infoMB, SIGNAL( clicked() ), &f1, SLOT(info()));
	qApp->connect(titlelist, SIGNAL(itemSelectionChanged()), &fp, SLOT(chMusInfo()));
	qApp->connect(&timChImgs, SIGNAL(timeout()), &fp, SLOT(chMusInfoTimer()));
	qApp->connect(fp.ui.searchBarE, SIGNAL(returnPressed()), &fp, SLOT(searchMus()));

//FormSetup
	qApp->connect(fs.ui.applyButton, SIGNAL(clicked()), &fs, SLOT(APPLYQMP()));
	qApp->connect(fs.ui.OKButton, SIGNAL(clicked()), &fs, SLOT(close()));
	qApp->connect(fs.ui.naf1Box, SIGNAL(stateChanged(int)), &fs, SLOT(naf1()));
	qApp->connect(fs.ui.loadPlugButton, SIGNAL(clicked()), &fs, SLOT(lpB()));
	qApp->connect(fs.ui.abPB, SIGNAL(clicked()), &fs, SLOT(aboutPlug()));
	qApp->connect(fs.ui.QMPButton, SIGNAL(clicked()), &fs, SLOT(QMPButton()));
	qApp->connect(fs.ui.nxtButton, SIGNAL(clicked()), &fs, SLOT(nxtButton()));
	qApp->connect(fs.ui.prevButton, SIGNAL(clicked()), &fs, SLOT(prevButton()));
	qApp->connect(fs.ui.setStyleB, SIGNAL(clicked()), &fs, SLOT(setStyleB()));
	qApp->connect(fs.ui.zVpluginaB, SIGNAL(clicked()), &fs, SLOT(zxplCC()));
	qApp->connect(fs.ui.zIpluginaB, SIGNAL(clicked()), &fs, SLOT(zxplCC()));
	qApp->connect(fs.ui.defB, SIGNAL(clicked()), &fs, SLOT(zxplCC()));
	qApp->connect(fs.ui.opcjePB, SIGNAL(clicked()), &fs, SLOT(opcjePB()));
	qApp->connect(fs.ui.pluginList, SIGNAL(customContextMenuRequested(QPoint)), &fs, SLOT(pluglistMenu()));
	qApp->connect(fs.ui.pluginList, SIGNAL( itemDoubleClicked(QListWidgetItem*) ), &fs, SLOT(opcjePB()));
	qApp->connect(fs.ui.delSetsButton, SIGNAL(clicked()), &fs, SLOT(delSetsB()));
	qApp->connect(fs.ui.langB, SIGNAL(clicked()), &fs, SLOT(langB()));
	qApp->connect(fs.ui.toUpB, SIGNAL(clicked()), &fs, SLOT(toUp()));
	qApp->connect(fs.ui.toDownB, SIGNAL(clicked()), &fs, SLOT(toDown()));
	qApp->connect(fs.ui.proxyB, SIGNAL( clicked() ), &fs, SLOT( proxyB() ) );
	qApp->connect(fs.ui.updB, SIGNAL( clicked() ), &f1, SLOT( checkUpdatesButton() ) );
	qApp->connect(fs.ui.pluginsL, SIGNAL( currentRowChanged(int) ), &fs, SLOT( pluginsChRow(int) ) );
	qApp->connect(fs.ui.dockB, SIGNAL( clicked() ), &fs, SLOT( formDockChOpen() ) );
	qApp->connect(fs.ui.svrAddressRestoreB, SIGNAL( clicked() ), &fs, SLOT( restoreAddress() ) );
	qApp->connect(fs.ui.fileStructB, SIGNAL( stateChanged(int) ), &fs, SLOT( fileStructBClicked(int) ) );

//FormFunc
	qApp->connect(ff.ui.closeB, SIGNAL(clicked()), &ff, SLOT(close()));
	qApp->connect(ff.ui.tabWidget, SIGNAL(currentChanged(int)), &ff, SLOT(tabCH(int)));

//FormStyle
	qApp->connect(fst.ui.OKB, SIGNAL(clicked()), &fst, SLOT(zamknij()));
	qApp->connect(fst.ui.styleCB, SIGNAL(currentIndexChanged(int)), &fst, SLOT(SetStyleConn()) );
	qApp->connect(fst.ui.applyColorsB, SIGNAL(clicked()), &fst, SLOT(applyColors()) );
	qApp->connect(fst.ui.addB, SIGNAL(clicked()), &fst, SLOT(newColor()) );
	qApp->connect(fst.ui.delB, SIGNAL(clicked()), &fst, SLOT(deleteColor()) );
	qApp->connect(fst.ui.scB, SIGNAL(clicked()), &fst, SLOT(SetEnabled()) );
	qApp->connect(fst.ui.ccB, SIGNAL(clicked()), &fst, SLOT(SetEnabled()) );
	qApp->connect(fst.ui.colorsB, SIGNAL(currentIndexChanged(int)), &fst, SLOT(ChIndex(int)) );
	qApp->connect(fst.ui.chNameB, SIGNAL(clicked()), &fst, SLOT(rename()) );
	qApp->connect(fst.ui.colorsB, SIGNAL(customContextMenuRequested(QPoint)), &fst, SLOT(resetColorMnu()));

//FormLang
	qApp->connect(fl.ui.OKB, SIGNAL(clicked()), &fl, SLOT(zamknij()));

//FormAbout
	qApp->connect(fa.ui.OKB, SIGNAL(clicked()), &fa, SLOT(close()));
	qApp->connect(fa.ui.cleanB, SIGNAL(clicked()), &fa, SLOT(cleanB()));
	qApp->connect(fa.ui.refB, SIGNAL(clicked()), &fa, SLOT(ref()));

//FormProp
	qApp->connect(fpr.ui.OKB, SIGNAL(clicked()), &fpr, SLOT(zamknij()));
	qApp->connect(fpr.ui.applyB, SIGNAL(clicked()), &fpr, SLOT(apply()));
	qApp->connect(fpr.ui.applyTB, SIGNAL(clicked()), &fpr, SLOT(applyT()));

//FormCopy
	qApp->connect(fcp.ui.brB, SIGNAL(clicked()), &fcp, SLOT(zamknij()));
	qApp->connect(&timCp, SIGNAL(timeout()), &fcp, SLOT(timer()));

//FormDockCh
	qApp->connect(fdck.ui.okB, SIGNAL(clicked()), &fdck, SLOT(OK()));
	qApp->connect(fdck.ui.dockList, SIGNAL(itemDoubleClicked(QListWidgetItem*)), &fdck, SLOT(OK()));

//FormDownload
	qApp->connect( fd.ui.brB, SIGNAL( clicked() ), &fd, SLOT( zamknij() ) );
	qApp->connect( fd.ui.instB, SIGNAL( clicked() ), &fd, SLOT( install() ) );

//miniQMP
	qApp->connect( mQ.ui.closeB, SIGNAL( clicked() ), &mQ, SLOT( hide() ) );
	qApp->connect( mQ.ui.playB, SIGNAL( clicked() ), &f1, SLOT( play() ) );
	qApp->connect( mQ.ui.pauseB, SIGNAL( clicked() ), &f1, SLOT( BTpause() ) );
	qApp->connect( mQ.ui.stopB, SIGNAL( clicked() ), &f1, SLOT( stop() ) );
	qApp->connect( mQ.ui.nextB, SIGNAL( clicked() ), &f1, SLOT( nextB() ) );
	qApp->connect( mQ.ui.prevB, SIGNAL( clicked() ), &f1, SLOT( prevB() ) );
#ifndef Q_OS_MAC
	qApp->connect( mQ.ui.titleL, SIGNAL( customContextMenuRequested(QPoint) ), &f1, SLOT( showTrayMnu() ) );
#endif
	qApp->connect( mQ.ui.volS, SIGNAL ( valueChanged(int) ), &f1, SLOT( setVolFromMiniQMP(int) ) );
	qApp->connect( mQ.ui.plistB, SIGNAL( clicked() ), &mQ, SLOT( plist() ) );

//QApplication
	qApp->connect( qApp, SIGNAL( aboutToQuit() ), &f1, SLOT( quit() ) );
}
