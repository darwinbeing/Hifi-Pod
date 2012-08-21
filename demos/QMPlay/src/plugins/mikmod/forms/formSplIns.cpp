void FormSplIns::zamknij()
{
	close();
}

void FormSplIns::Init()
{
	int ms;
	char tmp [100];

	fsi.move(fsiposX,fsiposY);
	fsi.resize(fsisW,fsisH);

	ms = module->numsmp +1;
	ui.sampleBox->clear();
	for (int i = 1 ; i < ms; i++)
	{
		sprintf(tmp,"%i: %s",i,module->samples[i-1].samplename);
		ui.sampleBox->addItem( tmp );
	}

	ms = module->numins +1;
	ui.instrBox->clear();
	if (module->flags&UF_INST)
		for (int i = 1 ; i<ms; i++)
	{
		sprintf(tmp,"%i: %s",i,module->instruments[i-1].insname);
		ui.instrBox->addItem( tmp );
	}

}

void FormSplIns::closeEvent(QCloseEvent*)
{
	fsiposX=x();
	fsiposY=y();
	fsisW=width();
	fsisH=height();
}
