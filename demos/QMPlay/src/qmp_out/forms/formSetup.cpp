void FormSetup::Init()
{
	fs.ui.mbsL->setText( "" );
	fs.ui.bsL->setText ( "" );
	fs.ui.bufQL->setText ( "" );

	ui.chChnNotB-> setChecked ( true      );

	ui.bB       -> setChecked ( bB        );
	ui.volB     -> setChecked ( useAppVol );
	ui.savEffB  -> setChecked ( savEff    );
	ui.visEffB  -> setChecked ( visEff    );
	ui.playSB   -> setChecked ( toOplugS  );
	ui.playSExB -> setChecked ( toOplugEx );
	ui.sL       -> setValue   ( sL        );
	ui.sR       -> setValue   ( sR        );
	ui.bEffB    -> setChecked ( bEff      );
	ui.chChnB   -> setChecked ( chChnB    );
	ui.zChnB    -> setChecked ( zChnB     );
	ui.chChn2B  -> setChecked ( chChn2B   );
	ui.pSL      -> setValue   ( _priority );
	ui.titleEB  -> setChecked ( titleE    );
	ui.silenceB -> setChecked ( silenceB  );

	ui.sL -> setToolTip( QString::number( ui.sL->value() ) );
	ui.sR -> setToolTip( QString::number( ui.sL->value() ) );

	playSB();

	//druga karta
	ui.userRateB -> setChecked( userRate );
	ui.userBitsB -> setChecked( userBits );
	ui.userChnB  -> setChecked( userChn  );
	ui.rateB     -> setValue  ( UserRate );
	ui.chnB      -> setValue  ( UserChn  );
	switch( UserBits )
	{
		case 8:
			ui.bits8B  -> setChecked(true);
			break;
		case 24:
			ui.bits24B -> setChecked(true);
			break;
		case 32:
			ui.bits32B -> setChecked(true);
			break;
		default:
			ui.bits16B -> setChecked(true);
			break;
	}

	userRateB();
	userBitsB();
	userChnB();

	ui.titleB         -> setChecked( titleB        );
	ui.titleHB        -> setChecked( titleHB       );
	ui.buffQB         -> setChecked( BufQ          );
	ui.QBufB          -> setValue  ( QBuf          );
	ui.soundBB        -> setValue  ( soundB        );
	ui.buffQIfNeadedB -> setChecked( buffQIfNeaded );

	_buffQB();
	_titleHB();
}

void FormSetup::APPLY()
{
	useAppVol = ui.volB     -> isChecked();
	savEff    = ui.savEffB  -> isChecked();
	visEff    = ui.visEffB  -> isChecked();
	toOplugS  = ui.playSB   -> isChecked();
	toOplugEx = ui.playSExB -> isChecked();
	bEff      = ui.bEffB    -> isChecked();
	chChnB    = ui.chChnB   -> isChecked();
	zChnB     = ui.zChnB    -> isChecked();
	chChn2B   = ui.chChn2B  -> isChecked();
	_priority = ui.pSL      -> value    ();
	titleE    = ui.titleEB  -> isChecked();
	silenceB  = ui.silenceB -> isChecked();

	musParam[3] = QString::number( _priority );

	Save.zapiszopcje();

	//druga karta
	int tmpUserBits(16);
	if ( ui.bits8B  -> isChecked() )
		tmpUserBits = 8;
	if ( ui.bits24B -> isChecked() )
		tmpUserBits = 24;
	if ( ui.bits32B -> isChecked() )
		tmpUserBits = 32;
	if
	(
		userRate      != ui.userRateB   -> isChecked() ||
		userBits      != ui.userBitsB   -> isChecked() ||
		userChn       != ui.userChnB    -> isChecked() ||
		UserRate      != ui.rateB       -> value    () ||
		UserChn       != ui.chnB        -> value    () ||
		UserBits      != tmpUserBits                   ||
		BufQ          != ui.buffQB      -> isChecked() ||
		QBuf          != ui.QBufB       -> value    () ||
		soundB        != ui.soundBB     -> value    () ||
		buffQIfNeaded != ui.buffQIfNeadedB -> isChecked()
	)
		mustReset = true;

	userRate = ui.userRateB -> isChecked();
	userBits = ui.userBitsB -> isChecked();
	userChn  = ui.userChnB  -> isChecked();
	UserRate = ui.rateB     -> value    ();
	UserChn  = ui.chnB      -> value    ();
	UserBits = tmpUserBits;

	titleB        = ui.titleB         -> isChecked();
	titleHB       = ui.titleHB        -> isChecked();
	BufQ          = ui.buffQB         -> isChecked();
	QBuf          = ui.QBufB          -> value    ();
	soundB        = ui.soundBB        -> value    ();
	buffQIfNeaded = ui.buffQIfNeadedB -> isChecked();

	check4err();
}

void FormSetup::check4err()
{
	switch( UserChn )
	{
		case 3:
			UserChn = 2;
			break;
		case 5:
			UserChn = 4;
			break;
		case 7:
			UserChn = 6;
			break;
	}
	ui.chnB->setValue(UserChn);
}

void FormSetup::bBset()
{
	bB = ui.bB -> isChecked();
	Save.zapiszBb();
}

void FormSetup::ApplyB()
{
	APPLY();
	Save.zapiszopcje();
}

void FormSetup::playSB()
{
	if ( ui.playSB -> isChecked() )
		ui.playSExB -> setEnabled ( true );
	else
	{
		ui.playSExB -> setEnabled ( false );
		ui.playSExB -> setChecked ( false );
	}
}

void FormSetup::setVol( int V )
{
	if ( bB )
	{
		sL = V;
		sR = V;
		ui.sL -> setValue ( V );
		ui.sR -> setValue ( V );
	}
	else
	{
		if ( ui.sL->hasFocus() )
			sL = V;
		if ( ui.sR->hasFocus() )
			sR = V;
	}
	ui.sL -> setToolTip( QString::number( ui.sL->value() ) );
	ui.sR -> setToolTip( QString::number( ui.sL->value() ) );
	if ( useAppVol )
	{
		int C[2];
		C[0] = ui.sL->value();
		C[1] = ui.sR->value();
		QLib->setVol( C );
	}
	setOPlugVolume();
}

void FormSetup::userBitsB()
{
	ui.bitsB -> setEnabled( ui.userBitsB -> isChecked() );
}
void FormSetup::userRateB()
{
	ui.rateB -> setEnabled( ui.userRateB -> isChecked() );
}
void FormSetup::userChnB()
{
	ui.chnB -> setEnabled( ui.userChnB -> isChecked() );
}
void FormSetup::_buffQB()
{
	ui.QBufB->setEnabled( ui.buffQB->isChecked() );
	ui.buffQIfNeadedB->setEnabled( ui.buffQB->isChecked() );
}
void FormSetup::_titleHB()
{
	ui.titleHB->setEnabled ( ui.titleB->isChecked() );
}

void FormSetup::updateBufferSize(QString s1, QString s2, int s3)
{
	fs.ui.mbsL->setText( s1 );
	fs.ui.bsL->setText( s2 );
	switch(s3)
	{
		case -1:
			fs.ui.bufQL->setText( "" );
			break;
		case 0:
			fs.ui.bufQL->setText( Texts[8] );
			break;
		case 1:
			fs.ui.bufQL->setText( Texts[9] );
			break;
	}
	fs.ui.mbsL->update();
	fs.ui.bsL->update();
	fs.ui.bufQL->update();
}
