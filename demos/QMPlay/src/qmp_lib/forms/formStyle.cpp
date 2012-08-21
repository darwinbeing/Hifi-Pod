const QString colorExt = ".qmpcolor";

QMenu mnuReset;

bool allowChStyle(1), allowChColor(1),  ResetColor(0);
QSettings *colorSet;

QFont SystemFont;
QPalette systemPalette, applicationPalette, mainWindowPalette;
QColor sliderButtonColor;
QPixmap mainWindowPixmap;
bool ReadOnly(0);

void FormStyle::getSystemPalette()
{
#ifdef Q_OS_MAC
	ui.bF1->setVisible( false );
	ui.bFSize1->setVisible( false );
#endif
	systemPalette = qApp->palette();
	SystemFont = qApp->font();
}

bool FormStyle::chkName( QString n )
{
	for ( int i = 0 ; i < ui.colorsB->count() ; i++ )
	{
		if ( ui.colorsB->itemText(i).toLower() == n.toLower() )
		{
			QMessageBox::warning( this, "QMPlay", Texts[118] /* Ta nazwa jest już używana! */ );
			return 1;
		}
	}
	return 0;
}

void FormStyle::newColor()
{
	if ( !ui.colorE->text().isEmpty() )
	{
		if ( chkName( ui.colorE->text() ) )
			return;
		allowChColor = false;
		ui.colorsB->addItem( ui.colorE->text() );
		ui.colorsB->setCurrentIndex( ui.colorsB->count() - 1 );
		allowChColor = true;
		ReadOnly = false;
		applyColors();
	}
}
void FormStyle::deleteColor()
{
	if ( ui.colorsB->currentIndex() > -1 )
	{
		if ( ReadOnly )
		{
			_ReadOnly();
			return;
		}
		QFile::remove( "colors/"+ui.colorsB->currentText()+colorExt );
		LoadColorList();
	}
}
void FormStyle::rename()
{
	if ( ui.colorsB->currentIndex() > -1 )
	{
		if ( ReadOnly )
		{
			_ReadOnly();
			return;
		}
		if ( chkName( ui.colorE->text() ) )
			return;
		QFile::rename( "colors/"+ui.colorsB->currentText()+colorExt, "colors/"+ui.colorE->text()+colorExt );
		QString tmpName = ui.colorE->text();
		LoadColorList();
		int currIdx(0);
		for ( ; currIdx < ui.colorsB->count() ; currIdx++ )
			if ( tmpName == ui.colorsB->itemText( currIdx ) )
				break;
		ui.colorsB->setCurrentIndex(currIdx);
	}
}

void FormStyle::SetCustomPalette()
{
	if ( ui.colorsB->currentIndex() < 0 )
		return;

	colorSet = new QSettings( "colors/"+ui.colorsB->currentText()+colorExt,QSettings::IniFormat );

	ReadOnly = colorSet->value("QMPColorFileInfo/ReadOnly").toBool();

	mainWindowPixmap = colorSet->value("QMPColor/mainWindowPixmap").value<QPixmap>();
	ui.use2->setChecked( colorSet->value("QMPColor/mainWindowUse2").toBool() );
	ui.bP2_1->setValue( colorSet->value("QMPColor/mainWindowbP2_1").toDouble() );
	ui.bHt2->setChecked( colorSet->value("QMPColor/mainWindowbHt2").toBool() );
	ui.bSt2->setChecked( colorSet->value("QMPColor/mainWindowbSt2").toBool() );

	applicationPalette = colorSet->value("QMPColor/applicationPalette").value<QPalette>();

	sliderButtonColor = colorSet->value("QMPColor/sliderButtonColor").value<QColor>();

#ifdef Q_WS_X11
	QString fN = colorSet->value("QMPFont/applicationFontNameX11").toString();
#endif
// #ifdef Q_OS_MAC
// 	QString fN = colorSet->value("QMPFont/applicationFontNameMac").toString();
// #endif
#ifdef Q_WS_WIN
	QString fN = colorSet->value("QMPFont/applicationFontNameWin").toString();
#endif

#ifndef Q_OS_MAC
	if ( fN.isEmpty() )
		fN = SystemFont.toString();
	ui.bF1->setCurrentFont( fN );
	if ( ui.bF1->currentFont().toString() != fN )
		ui.bF1->setCurrentFont( SystemFont.toString() );
#endif

#ifdef Q_WS_X11
	int fS = colorSet->value("QMPFont/applicationFontSizeX11").toInt();
#endif
// #ifdef Q_OS_MAC
// 	int fS = colorSet->value("QMPFont/applicationFontSizeMac").toInt();
// #endif
#ifdef Q_WS_WIN
	int fS = colorSet->value("QMPFont/applicationFontSizeWin").toInt();
#endif

#ifndef Q_OS_MAC
	if ( !fS )
		fS = SystemFont.pointSize();
	ui.bFSize1->setValue( fS );
#endif

	delete colorSet;
}

void FormStyle::LoadColorList()
{
	QString oldColorScheme = colorScheme;

	ui.colorsB->clear();

	QDir qdir(qApp->applicationDirPath()+"/colors");
	QStringList fileList = qdir.entryList( QStringList( "*" + colorExt ), QDir::Files, QDir::Name );
	QStringList addToList;

	for ( int i = 0 ; i < fileList.count() ; i++ )
	{
		colorSet = new QSettings( "colors/"+fileList[i],QSettings::IniFormat );

		if ( colorSet->value("QMPColorFileInfo/QMPColor").toBool() )
			addToList += fileList[i].left( fileList[i].length() - colorExt.length() );

		delete colorSet;
	}

	ui.colorsB->addItems( addToList );

	int idxDefCol(-1), idxCol(-1);
	for ( int currIdx = 0 ; currIdx < ui.colorsB->count() ; currIdx++ )
	{
		if ( ui.colorsB->itemText( currIdx ) == defColorScheme )
			idxDefCol = currIdx;
		if ( ui.colorsB->itemText( currIdx ) == oldColorScheme )
			idxCol = currIdx;
	}
	if ( idxCol != -1 )
		ui.colorsB->setCurrentIndex( idxCol );
	else if ( idxDefCol != -1 )
		ui.colorsB->setCurrentIndex( idxDefCol );
	else
		ui.colorsB->setCurrentIndex( 0 );
}

void FormStyle::SetEnabled()
{
	bool tmpAllowChColor = allowChColor;
	allowChColor = false;
	if ( ui.ccB->isChecked() )
	{
		ui.groupBox->setEnabled(true);
		LoadColorList();
		SetCustomPalette();
		ui.mainWindowSets->setEnabled( ui.use2->isChecked() );
		ui.colorE->setText( ui.colorsB->currentText() );
	}
	else
	{
		ui.groupBox->setEnabled(false);
		applicationPalette = systemPalette;
		mainWindowPalette = systemPalette;
	}
	allowChColor = tmpAllowChColor;
	if ( allowChColor )
		SetColor();
	else if ( ui.scB->isChecked() )
		sliderButtonColor = qApp->palette().brush( QPalette::Button ).color();
}

void FormStyle::ChIndex( int i )
{
	if ( !allowChColor )
		return;
	ui.colorE->setText( ui.colorsB->itemText( i ) );
	SetCustomPalette();
	SetColor();
}

void FormStyle::setButtonsColor()
{
	if ( ui.ccB->isChecked() )
	{
		QPalette tmpPalette;

		tmpPalette.setBrush( QPalette::Button, applicationPalette.button() );
		ui.bC1_1->setPalette( tmpPalette );
		tmpPalette.setBrush( QPalette::Button, applicationPalette.window() );
		ui.bC1_2->setPalette( tmpPalette );
		tmpPalette.setBrush( QPalette::Button, applicationPalette.shadow() );
		ui.bC1_3->setPalette( tmpPalette );
		tmpPalette.setBrush( QPalette::Button, applicationPalette.highlight() );
		ui.bC1_4->setPalette( tmpPalette );
		tmpPalette.setBrush( QPalette::Button, applicationPalette.base() );
		ui.bC1_5->setPalette( tmpPalette );
		tmpPalette.setBrush( QPalette::Button, applicationPalette.text() );
		ui.bC1_6->setPalette( tmpPalette );
		tmpPalette.setBrush( QPalette::Button, applicationPalette.highlightedText() );
		ui.bC1_7->setPalette( tmpPalette );
		tmpPalette.setBrush( QPalette::Button, sliderButtonColor );
		ui.bC1_8->setPalette( tmpPalette );

		if ( !mainWindowPixmap.isNull() )
		{
			QBrush brushW( mainWindowPixmap.scaled( ui.bP2_2->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation ) );
			tmpPalette.setBrush( QPalette::Button, brushW );
			ui.bP2_2->setPalette( tmpPalette );
		}
		else
			ui.bP2_2->setPalette( qApp->palette() );
	}
	else
	{
		ui.bC1_1->setPalette( qApp->palette() );
		ui.bC1_2->setPalette( qApp->palette() );
		ui.bC1_3->setPalette( qApp->palette() );
		ui.bC1_4->setPalette( qApp->palette() );
		ui.bC1_5->setPalette( qApp->palette() );
		ui.bC1_6->setPalette( qApp->palette() );
		ui.bC1_7->setPalette( qApp->palette() );
		ui.bC1_8->setPalette( qApp->palette() );

		ui.bP2_2->setPalette( qApp->palette() );
	}
}

void FormStyle::PictureButtonCliked()
{
	QString pMS = Func.fileDialog( OPEN_FILE, this, "QMPlay", curP, Texts[34]/*Obrazy*/ + " (*.bmp *.gif *.jpg *.jpeg *.png *.pbm *.pgm *.ppm *.xbm *.xpm *.ico *.svg);;" + Texts[30] + " (*)" )[0];
	if ( !pMS.isEmpty() )
	{
		Func.CURP(pMS);
		if ( focusWidget()->objectName() == "bP2_2" )
			mainWindowPixmap = pMS;
	}
	else if ( !mainWindowPixmap.isNull() && QMessageBox::information( this,"QMPlay",Texts[121]/*czy wyczyscic obraz*/,3,4 ) == 3 )
		mainWindowPixmap = 0;
	setButtonsColor();
}

void FormStyle::GlobalColorButtonCliked()
{
	QColor initialColor;
	if ( focusWidget()->objectName() == "bC1_1" )
		initialColor = applicationPalette.button().color().rgba();
	else if ( focusWidget()->objectName() == "bC1_2" )
		initialColor = applicationPalette.window().color().rgba();
	else if ( focusWidget()->objectName() == "bC1_3" )
		initialColor = applicationPalette.shadow().color().rgba();
	else if ( focusWidget()->objectName() == "bC1_4" )
		initialColor = applicationPalette.highlight().color().rgba();
	else if ( focusWidget()->objectName() == "bC1_5" )
		initialColor = applicationPalette.base().color().rgba();
	else if ( focusWidget()->objectName() == "bC1_6" )
		initialColor = applicationPalette.text().color().rgba();
	else if ( focusWidget()->objectName() == "bC1_7" )
		initialColor = applicationPalette.highlightedText().color().rgba();
	else if ( focusWidget()->objectName() == "bC1_8" )
		initialColor = sliderButtonColor.rgb();
	else
		initialColor = Qt::white;

	QColor color = QColorDialog::getColor( initialColor, this, Texts[ 119 ] /*Wybierz kolor*/, QColorDialog::DontUseNativeDialog );

	if ( !color.isValid() )
		return;

	if ( focusWidget()->objectName() == "bC1_1" )
		applicationPalette.setBrush( QPalette::Button, color );
	else if ( focusWidget()->objectName() == "bC1_2" )
		applicationPalette.setBrush( QPalette::Window, color );
	else if ( focusWidget()->objectName() == "bC1_3" )
	{
		applicationPalette.setBrush( QPalette::Shadow, color );
		applicationPalette.setBrush( QPalette::Light, color );
		applicationPalette.setBrush( QPalette::Dark, color );
	} else if ( focusWidget()->objectName() == "bC1_4" )
		applicationPalette.setBrush( QPalette::Highlight, color );
	else if ( focusWidget()->objectName() == "bC1_5" )
		applicationPalette.setBrush( QPalette::Base, color );
	else if ( focusWidget()->objectName() == "bC1_6" )
	{
		applicationPalette.setBrush( QPalette::Text, color );
		applicationPalette.setBrush( QPalette::WindowText, color );
		applicationPalette.setBrush( QPalette::ButtonText, color );
	} else if ( focusWidget()->objectName() == "bC1_7" )
		applicationPalette.setBrush( QPalette::HighlightedText, color );
	else if ( focusWidget()->objectName() == "bC1_8" )
		sliderButtonColor = color;

	setButtonsColor();
}

void FormStyle::_ReadOnly()
{
	QMessageBox::warning( this, ui.colorsB->currentText(), Texts[120] /* "Tylko do odczytu!" */ );
}

void FormStyle::_applyColors(bool b)
{
	if ( ui.scB->isChecked() )
		return;

	if ( ui.colorsB->currentIndex() < 0 )
		return;
	if ( ReadOnly )
	{
		SetColor();
		if ( b )
			_ReadOnly();
		return;
	}

	colorSet = new QSettings( "colors/"+ui.colorsB->currentText()+colorExt,QSettings::IniFormat );

	colorSet->setValue("QMPColorFileInfo/QMPColor",true);
	colorSet->setValue("QMPColorFileInfo/ReadOnly",false);

	colorSet->setValue("QMPColor/mainWindowPixmap",0);
	colorSet->setValue("QMPColor/mainWindowUse2",ui.use2->isChecked());
	colorSet->setValue("QMPColor/mainWindowbP2_1",ui.bP2_1->value());
	colorSet->setValue("QMPColor/mainWindowbHt2",ui.bHt2->isChecked());
	colorSet->setValue("QMPColor/mainWindowbSt2",ui.bSt2->isChecked());
	if ( ui.use2->isChecked() )
		colorSet->setValue("QMPColor/mainWindowPixmap",mainWindowPixmap);

	colorSet->setValue("QMPColor/applicationPalette",applicationPalette);

#ifdef Q_WS_X11
	colorSet->setValue("QMPFont/applicationFontNameX11",ui.bF1->currentFont().toString());
#endif
// #ifdef Q_OS_MAC
// 	colorSet->setValue("QMPFont/applicationFontNameMac",ui.bF1->currentFont().toString());
// #endif
#ifdef Q_WS_WIN
	colorSet->setValue("QMPFont/applicationFontNameWin",ui.bF1->currentFont().toString());
#endif

#ifdef Q_WS_X11
	colorSet->setValue("QMPFont/applicationFontSizeX11",ui.bFSize1->value());
#endif
// #ifdef Q_OS_MAC
// 	colorSet->setValue("QMPFont/applicationFontSizeMac",ui.bFSize1->value());
// #endif
#ifdef Q_WS_WIN
	colorSet->setValue("QMPFont/applicationFontSizeWin",ui.bFSize1->value());
#endif

	colorSet->setValue("QMPColor/sliderButtonColor",sliderButtonColor);

	delete colorSet;

	SetColor();
}
void FormStyle::applyColors()
{
	_applyColors(1);
}

void FormStyle::Init()
{
	allowChColor = false;
	SetEnabled();
	allowChColor = true;

	if ( styl.isEmpty() )
		styl = Default_QMP_style;

	allowChStyle = false;
	ui.styleCB->clear();
	ui.styleCB->addItems( QStyleFactory::keys() );
	for ( int i = 0 ; i < ui.styleCB->count() ; i++ )
	{
		if ( ui.styleCB->itemText( i ).contains( styl , Qt::CaseInsensitive ) )
		{
			ui.styleCB->setCurrentIndex( i );
			break;
		}
	}
	allowChStyle = true;

	connect(ui.bC1_1, SIGNAL(clicked()), this, SLOT(GlobalColorButtonCliked()));
	connect(ui.bC1_2, SIGNAL(clicked()), this, SLOT(GlobalColorButtonCliked()));
	connect(ui.bC1_3, SIGNAL(clicked()), this, SLOT(GlobalColorButtonCliked()));
	connect(ui.bC1_4, SIGNAL(clicked()), this, SLOT(GlobalColorButtonCliked()));
	connect(ui.bC1_5, SIGNAL(clicked()), this, SLOT(GlobalColorButtonCliked()));
	connect(ui.bC1_6, SIGNAL(clicked()), this, SLOT(GlobalColorButtonCliked()));
	connect(ui.bC1_7, SIGNAL(clicked()), this, SLOT(GlobalColorButtonCliked()));
	connect(ui.bC1_8, SIGNAL(clicked()), this, SLOT(GlobalColorButtonCliked()));
	connect(ui.bP2_2, SIGNAL(clicked()), this, SLOT(PictureButtonCliked()));
	connect(ui.use2,  SIGNAL(stateChanged(int)), this, SLOT(mainWindowSetsEnabled(int)));
}

void FormStyle::SetStyleConn()
{
	SetStyle(1);
	if ( allowChStyle && ui.ccB->isChecked() )
		SetColor();
}

void FormStyle::SetStyle(bool b)
{
	if (!allowChStyle)
		return;
	if (b)
		styl = ui.styleCB->currentText();
	if ( !QStyleFactory::create( styl ) )
	{
		styl = Default_QMP_style;
		if ( !QStyleFactory::create( styl ) )
			styl = Default_QMP_style2;
	}
	qApp->setStyle( styl );
}

void FormStyle::quickSetColor()
{
	QFont globalFont = SystemFont;

	if ( ui.ccB->isChecked() && !ResetColor )
	{
		qApp->setPalette( applicationPalette );

		QPalette qSliderPalette;
		qSliderPalette.setBrush( QPalette::Button, sliderButtonColor );
		qApp->setPalette( qSliderPalette, "QSlider" );

		if ( ui.use2->isChecked() )
		{
			QPalette tmpPalette = qApp->palette();

			if ( !mainWindowPixmap.isNull() )
			{
				QBrush brushW( mainWindowPixmap.scaled( f1.size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation ) );
				tmpPalette.setBrush( QPalette::Window, brushW );
			}

			QColor colorA;

			colorA = tmpPalette.button().color();
			colorA.setAlphaF( ui.bP2_1->value() );
			tmpPalette.setBrush( QPalette::Button, colorA );

			colorA = tmpPalette.base().color();
			colorA.setAlphaF( ui.bP2_1->value() );
			tmpPalette.setBrush( QPalette::Base, colorA );

			if ( ui.bHt2->isChecked() )
			{
				colorA = tmpPalette.highlight().color();
				colorA.setAlphaF( ui.bP2_1->value() );
				tmpPalette.setBrush( QPalette::Highlight, colorA );
			}

			if ( ui.bSt2->isChecked() )
			{
				colorA = tmpPalette.shadow().color();
				colorA.setAlphaF( ui.bP2_1->value() );
				tmpPalette.setBrush( QPalette::Shadow, colorA );
			}

			f1.setPalette( tmpPalette );
		}
		else
		{
			f1.setPalette( qApp->palette() );
		}

		globalFont = ui.bF1->currentFont();
		globalFont.setPointSize( ui.bFSize1->value() );
	}
	else
	{
		qApp->setPalette( systemPalette );
		f1.setPalette( qApp->palette() );
		sliderButtonColor = qApp->palette().brush( QPalette::Button ).color();
	}

	if ( ResetColor )
	{
		ResetColor = false;
		applicationPalette = systemPalette;
		ui.bF1->setCurrentFont( SystemFont.toString() );
		ui.bFSize1->setValue( SystemFont.pointSize() );
	}

	QColor col = qApp->palette().window().color();
	col.setAlphaF( ui.bP2_1->value() );
	fsl.SetColor( col );

	f1.ui.pbL->setPalette( qApp->palette() );
	f1.ui.pbR->setPalette( qApp->palette() );

	globalFont.setBold( false );
	globalFont.setItalic( false );
	globalFont.setUnderline( false );
	if ( globalFont.pointSize() > 14 )
		globalFont.setPointSize( 14 );
	else if ( globalFont.pointSize() < 6 )
		globalFont.setPointSize( 6 );
#ifndef Q_OS_MAC
	qApp->setFont( globalFont );
#endif
}

void FormStyle::SetColor()
{
	QMP_RUN_OS os = getOS();
	if ( os == QMP_MAC || ( os != QMP_WINDOWS && styl == "QtCurve" ) )
		QTimer::singleShot( 0, this, SLOT( quickSetColor() ) );
	quickSetColor();
	setButtonsColor();
	if ( !ui.colorsB->currentText().isEmpty() )
		colorScheme = ui.colorsB->currentText();
	resetTray();
}

void FormStyle::resetTray()
{
	if ( tray.isVisible() )
	{
#ifdef Q_WS_X11
		tray.hide();
#else
		return;
#endif
	}
	tray.show();
}

void FormStyle::miniApply()
{
	fst.SetStyle(0);
	resetTray();
}
void FormStyle::applyAll()
{
	allowChColor = false;
	LoadColorList();
	if ( ui.colorsB->count() == 0 )
		ui.scB->setChecked(true);
	SetCustomPalette();
	SetStyle(0);
	allowChColor = true;
	SetColor();
}

void FormStyle::zamknij()
{
	_applyColors(0);
	close();
}

void FormStyle::mainWindowSetsEnabled( int c )
{
	ui.mainWindowSets->setEnabled( c );
}

void FormStyle::resetColor()
{
	ResetColor = true;
	quickSetColor();
	setButtonsColor();
}
void FormStyle::resetColorMnu()
{
	mnuReset.clear();
	if ( ReadOnly )
		return;
	mnuReset.addAction( Texts[127] /* Resetuj kolor */, this, SLOT( resetColor() ) );
	mnuReset.popup(QCursor::pos());
}

void FormStyle::closeEvent(QCloseEvent*)
{
	disconnect(ui.bC1_1, SIGNAL(clicked()), this, SLOT(GlobalColorButtonCliked()));
	disconnect(ui.bC1_2, SIGNAL(clicked()), this, SLOT(GlobalColorButtonCliked()));
	disconnect(ui.bC1_3, SIGNAL(clicked()), this, SLOT(GlobalColorButtonCliked()));
	disconnect(ui.bC1_4, SIGNAL(clicked()), this, SLOT(GlobalColorButtonCliked()));
	disconnect(ui.bC1_5, SIGNAL(clicked()), this, SLOT(GlobalColorButtonCliked()));
	disconnect(ui.bC1_6, SIGNAL(clicked()), this, SLOT(GlobalColorButtonCliked()));
	disconnect(ui.bC1_7, SIGNAL(clicked()), this, SLOT(GlobalColorButtonCliked()));
	disconnect(ui.bC1_8, SIGNAL(clicked()), this, SLOT(GlobalColorButtonCliked()));
	disconnect(ui.bP2_2, SIGNAL(clicked()), this, SLOT(PictureButtonCliked()));
	disconnect(ui.use2,  SIGNAL(stateChanged(int)), this, SLOT(mainWindowSetsEnabled(int)));
}
