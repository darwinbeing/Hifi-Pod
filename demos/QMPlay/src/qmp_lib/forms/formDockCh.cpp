void FormDock::Init()
{
	ui.dockList->clear();
	ui.dockList->addItem( "\n\n" + Texts[124] + "\n\n" /* "Brak" */ );
	ui.dockList->addItem( "\n---\n" );
	ui.dockList->setCurrentRow(0);

	ui.dockList->addItem( formInfo.objectName() );
	ui.dockList->item(ui.dockList->count()-1)->setIcon(QIcon(QPixmap::grabWidget(&formInfo,formInfo.rect())));
	if ( inDockObjName == formInfo.objectName() )
		ui.dockList->setCurrentRow( ui.dockList->count()-1 );

	QWidget *tmpW;
	if ( equalizer )
	{
		if ( equalizer->pluginInfo->canDock )
		{
			tmpW = equalizer->pluginInfo->canDock(0);
			if ( tmpW && !tmpW->objectName().isEmpty() )
			{
				ui.dockList->addItem( tmpW->objectName() );
				ui.dockList->item(ui.dockList->count()-1)->setIcon(QIcon(QPixmap::grabWidget(tmpW,tmpW->rect())));
				if ( inDockObjName == tmpW->objectName() )
					ui.dockList->setCurrentRow( ui.dockList->count()-1 );
			}
		}
	}

	for ( int w = 0 ; w < pluginInfoList.size() ; w++ )
	{
		if ( pluginsList[3][w] == "y" && pluginInfoList[w]->canDock )
		{
			tmpW = pluginInfoList[w]->canDock(0);
			if ( tmpW && !tmpW->objectName().isEmpty() )
			{
				ui.dockList->addItem( tmpW->objectName() );
				ui.dockList->item(ui.dockList->count()-1)->setIcon(QIcon(QPixmap::grabWidget(tmpW,tmpW->rect())));
				if ( inDockObjName == tmpW->objectName() )
					ui.dockList->setCurrentRow( ui.dockList->count()-1 );
			}
		}
	}
}

void FormDock::applyDock()
{
	if ( !inDockObjName.isEmpty() )
	{
		if ( inDock && inDock->objectName() == inDockObjName )
			return;

		if ( formInfo.objectName() == inDockObjName )
		{
			formInfo.unDocking = true;
			formInfo.close();
			formInfo.unDocking = false;
			f1.showInfoForm();
			formInfo.button->setShortcut( QKeySequence() );
			f1.dockInF1( &formInfo, 0, formInfoUnDock );
			return;
		}

		QWidget *tmpW;
		if ( equalizer )
		{
			if ( equalizer->pluginInfo->canDock )
			{
				tmpW = equalizer->pluginInfo->canDock(0);
				if ( tmpW && tmpW->objectName() == inDockObjName )
				{
					equalizer->pluginInfo->canDock(1);
					f1.dockInF1( tmpW, 1, equalizer->pluginInfo->unDock );
					return;
				}
			}
		}

		for ( int w = 0 ; w < pluginInfoList.size() ; w++ )
		{
			if ( pluginsList[3][w] == "y" && pluginInfoList[w]->canDock )
			{
				tmpW = pluginInfoList[w]->canDock(0);
				if ( tmpW && tmpW->objectName() == inDockObjName )
				{
					pluginInfoList[w]->canDock(1);
					f1.dockInF1( tmpW, 1, pluginInfoList[w]->unDock );
					return;
				}
			}
		}
	}
	else
		f1.dockInF1( NULL, 0, NULL );
	inDockObjName.clear(); //jeżeli nic nie zadokuje
}

void FormDock::OK()
{
	if ( ui.dockList->currentRow() <= 0 )
		inDockObjName.clear();
	else if ( ui.dockList->currentRow() > 1 )
		inDockObjName = ui.dockList->currentItem()->text();
	ui.dockList->clear();
	applyDock();
	close();
}
