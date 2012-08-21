void FormCp::Init()
{
	ui.brB->setText( Texts[68] /**"Przerwij"*/ );
	ui.pB->setMaximum( cpthr.Count );
	ui.pB->setValue(0);
	ui.fL->setText("");
	timCp.start(25);
}

void FormCp::zamknij()
{
	close();
}

void FormCp::closeEvent(QCloseEvent*)
{
	timCp.stop();
	cpthr.doExit();
}

void FormCp::timer()
{
	ui.pB->setMaximum( cpthr.Count );
	ui.pB->setValue( cpthr.val );
	ui.fL->setText( Texts[65] /**Copy*/ + ": " + cpthr.fName );
	if ( cpthr.val > 0 && cpthr.val == cpthr.Count )
	{
		ui.brB->setText( Texts[66] /**Zamknij*/ );
		if ( cpthr.serror )
			ui.fL->setText( Texts[67] /**Done*/ );
		else
			ui.fL->setText( Texts[67] /**Done*/ + ", " +Texts[82] );
	}
}
