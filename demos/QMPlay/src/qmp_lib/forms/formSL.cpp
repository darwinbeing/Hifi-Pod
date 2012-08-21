void FormSL::clearVis()
{
	ui.bL_1->setEnabled(false);
	ui.bL_2->setEnabled(false);
	ui.bL_3->setEnabled(false);
	ui.bL_4->setEnabled(false);
	ui.bL_5->setEnabled(false);

	ui.bR_1->setEnabled(false);
	ui.bR_2->setEnabled(false);
	ui.bR_3->setEnabled(false);
	ui.bR_4->setEnabled(false);
	ui.bR_5->setEnabled(false);
}

void FormSL::SetColor( QColor col )
{
	QPalette tmpPal;

	tmpPal = ui.bL_1->palette();
	tmpPal.setBrush(QPalette::Disabled, QPalette::Button, col);
	ui.bL_1->setPalette( tmpPal );

	tmpPal = ui.bL_2->palette();
	tmpPal.setBrush(QPalette::Disabled, QPalette::Button, col);
	ui.bL_2->setPalette( tmpPal );

	tmpPal = ui.bL_3->palette();
	tmpPal.setBrush(QPalette::Disabled, QPalette::Button, col);
	ui.bL_3->setPalette( tmpPal );

	tmpPal = ui.bL_4->palette();
	tmpPal.setBrush(QPalette::Disabled, QPalette::Button, col);
	ui.bL_4->setPalette( tmpPal );

	tmpPal = ui.bL_5->palette();
	tmpPal.setBrush(QPalette::Disabled, QPalette::Button, col);
	ui.bL_5->setPalette( tmpPal );

	tmpPal = ui.bR_1->palette();
	tmpPal.setBrush(QPalette::Disabled, QPalette::Button, col);
	ui.bR_1->setPalette( tmpPal );

	tmpPal = ui.bR_2->palette();
	tmpPal.setBrush(QPalette::Disabled, QPalette::Button, col);
	ui.bR_2->setPalette( tmpPal );

	tmpPal = ui.bR_3->palette();
	tmpPal.setBrush(QPalette::Disabled, QPalette::Button, col);
	ui.bR_3->setPalette( tmpPal );

	tmpPal = ui.bR_4->palette();
	tmpPal.setBrush(QPalette::Disabled, QPalette::Button, col);
	ui.bR_4->setPalette( tmpPal );

	tmpPal = ui.bR_5->palette();
	tmpPal.setBrush(QPalette::Disabled, QPalette::Button, col);
	ui.bR_5->setPalette( tmpPal );
}

void FormSL::setVis(int s[2])
{
	int z[2];
	z[0] = s[0] / 16;
	z[1] = s[1] / 16;
	switch ( z[0] )
	{
		case 0:
			ui.bL_1->setEnabled(false);
			ui.bL_2->setEnabled(false);
			ui.bL_3->setEnabled(false);
			ui.bL_4->setEnabled(false);
			ui.bL_5->setEnabled(false);
			break;
		case 1:
			ui.bL_1->setEnabled(true);
			ui.bL_2->setEnabled(false);
			ui.bL_3->setEnabled(false);
			ui.bL_4->setEnabled(false);
			ui.bL_5->setEnabled(false);
			break;
		case 2:
			ui.bL_1->setEnabled(true);
			ui.bL_2->setEnabled(true);
			ui.bL_3->setEnabled(false);
			ui.bL_4->setEnabled(false);
			ui.bL_5->setEnabled(false);
			break;
		case 3:
			ui.bL_1->setEnabled(true);
			ui.bL_2->setEnabled(true);
			ui.bL_3->setEnabled(true);
			ui.bL_4->setEnabled(false);
			ui.bL_5->setEnabled(false);
			break;
		case 4:
			ui.bL_1->setEnabled(true);
			ui.bL_2->setEnabled(true);
			ui.bL_3->setEnabled(true);
			ui.bL_4->setEnabled(true);
			ui.bL_5->setEnabled(false);
			break;
		case 5:
			ui.bL_1->setEnabled(true);
			ui.bL_2->setEnabled(true);
			ui.bL_3->setEnabled(true);
			ui.bL_4->setEnabled(true);
			ui.bL_5->setEnabled(true);
			break;
	}
	switch ( z[1] )
	{
		case 0:
			ui.bR_1->setEnabled(false);
			ui.bR_2->setEnabled(false);
			ui.bR_3->setEnabled(false);
			ui.bR_4->setEnabled(false);
			ui.bR_5->setEnabled(false);
			break;
		case 1:
			ui.bR_1->setEnabled(true);
			ui.bR_2->setEnabled(false);
			ui.bR_3->setEnabled(false);
			ui.bR_4->setEnabled(false);
			ui.bR_5->setEnabled(false);
			break;
		case 2:
			ui.bR_1->setEnabled(true);
			ui.bR_2->setEnabled(true);
			ui.bR_3->setEnabled(false);
			ui.bR_4->setEnabled(false);
			ui.bR_5->setEnabled(false);
			break;
		case 3:
			ui.bR_1->setEnabled(true);
			ui.bR_2->setEnabled(true);
			ui.bR_3->setEnabled(true);
			ui.bR_4->setEnabled(false);
			ui.bR_5->setEnabled(false);
			break;
		case 4:
			ui.bR_1->setEnabled(true);
			ui.bR_2->setEnabled(true);
			ui.bR_3->setEnabled(true);
			ui.bR_4->setEnabled(true);
			ui.bR_5->setEnabled(false);
			break;
		case 5:
			ui.bR_1->setEnabled(true);
			ui.bR_2->setEnabled(true);
			ui.bR_3->setEnabled(true);
			ui.bR_4->setEnabled(true);
			ui.bR_5->setEnabled(true);
			break;
	}
}
