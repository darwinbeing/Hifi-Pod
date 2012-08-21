void FormSetup::Init()
{
	ui.fPthE->setText( fPth );
	ui.rawB->setChecked( raw );
	ui.schB->setChecked( sch );
}

void FormSetup::browse()
{
	QString selfile = QLib->fileDialog( OPEN_DIR, this, Texts[2], fPth, "", NULL )[0];
	if ( !selfile.isEmpty() )
		ui.fPthE->setText( selfile );
}

void FormSetup::ApplyB()
{
	fPth = ui.fPthE->text();
	raw = ui.rawB->isChecked();
	sch = ui.schB->isChecked();

#ifdef Q_WS_WIN
	fPth.replace( '\\' , '/' );
#endif
	if ( fPth.right( 1 ) != "/" )
		fPth += "/";

	ui.fPthE->setText( fPth );

	Save.zapiszopcje();
}
