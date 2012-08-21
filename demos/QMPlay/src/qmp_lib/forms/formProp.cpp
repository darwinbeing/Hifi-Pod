int tmpX;

void FormProp::Init()
{
	if ( Func.nr() < 0 )
		return;

	fpr.move(fprPos);

	ui.adresE->setText("");
	ui.typeE->setText("");
	ui.nrL->setText("");
	ui.titleL->setText("");
	ui.fSizeL->setText("");

	int X = tmpX = Func.nr();

	ui.adresE->setText( playList[2][X] );

	QFile Fil( ui.adresE->text() );
	qint64 fSize = Fil.size();
	Fil.close();

	ui.fSizeL->setText( Func.getFSize(fSize) );

	ui.typeE->setText( playList[1][X] );

	ui.nrL->setText( QString::number( atoi( titlelist->item(X)->text().toAscii() ) ) );
	ui.titleL->setText( playList[0][X] );

	ui.pluginsB->clear();
	ui.pluginsB->addItem( "" );
	for ( int w = 0 ; w < Iplugins.size() ; w++ )
		if ( Iplugins[ w ]->pluginInfo->swOnOff( 0 ) )
			ui.pluginsB->addItem( Iplugins[ w ]->pluginInfo->Name );

	if ( ui.typeE->text().contains( "file" ) )
	{
		ui.fileB->setChecked(true);
		ui.label_6->setVisible(true);
		ui.fSizeL->setVisible(true);
	}
	if ( ui.typeE->text().contains( "plugin:" ) )
	{
		ui.pluginB->setChecked(true);
		ui.label_6->setVisible(false);
		ui.fSizeL->setVisible(false);
		QString typTmp = playList[1][X];
		typTmp = Func.getTypePlugin( typTmp );
		for ( int w = 0 ; w < ui.pluginsB->count() ; w++ )
		{
			if ( typTmp == ui.pluginsB->itemText( w ) )
			{
				ui.pluginsB->setCurrentIndex( w );
				break;
			}
		}
	}
	if ( ui.typeE->text().contains( "internet:" ) )
	{
		ui.adresB->setChecked(true);
		ui.label_6->setVisible(false);
		ui.fSizeL->setVisible(false);
		QString typTmp = playList[1][X];
		typTmp = typTmp.right( typTmp.size() - 9 );
		for ( int w = 0 ; w < ui.pluginsB->count() ; w++ )
		{
			if ( typTmp == ui.pluginsB->itemText( w ) )
			{
				ui.pluginsB->setCurrentIndex( w );
				break;
			}
		}
	}
}

void FormProp::closeEvent(QCloseEvent*)
{
	fprPos = pos();
}

void FormProp::zamknij()
{
	close();
}

void FormProp::apply()
{
	int X = Func.nr();

	if ( X != tmpX )
	{
		QMessageBox::information( this,"QMPlay",Texts[58] /*Wpis na liście nie zgadza się z otwartym*/ );
		return;
	}

	playList[2][X] = ui.adresE->text();
	playList[1][X] = ui.typeE->text();

	fp.updatePlistEntry(X);

	fprPos = pos();
	Init();
}

void FormProp::applyT()
{
	QString tmp;

	if ( ui.fileB->isChecked() )
	{
		tmp = "file";
		if ( ui.adresE->text().contains("plugin://") )
			ui.adresE->setText( "" );
		goto two;
	}
	if ( ui.pluginB->isChecked() )
		tmp = "plugin:";
	if ( ui.adresB->isChecked() )
		tmp = "internet:";

	if ( ui.pluginsB->currentIndex() >= 0 )
	{
		QString tmp2 = ui.pluginsB->itemText( ui.pluginsB->currentIndex() );
		if ( tmp == "internet:" && ( ui.adresE->text().left(9) == "plugin://" || ui.adresE->text()[0] == '/' || ui.adresE->text()[1] == ':' ) )
		{
			ui.adresE->setText( InternetProtocols[0] );
			ui.pluginsB->setCurrentIndex(0);
		}
		if ( tmp == "plugin:" )
		{
			if ( ui.adresE->text().left(9) == "plugin://" && ui.adresE->text().contains( tmp2 ) )
				tmp2 = ui.adresE->text().right( ui.adresE->text().length() - 9 );
			else
				ui.adresE->setText( tmp + "//" + tmp2 );
		}
		tmp += tmp2;
	}

	two:
	ui.typeE->setText( tmp );
}
