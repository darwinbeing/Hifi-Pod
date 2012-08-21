void FormMMSlider::Init()
{
	if (module->numchn > 1) fms.ui.S1->setVisible(true); else fms.ui.S1->setVisible(false);
	if (module->numchn > 2) fms.ui.S2->setVisible(true); else fms.ui.S2->setVisible(false);
	if (module->numchn > 3) fms.ui.S3->setVisible(true); else fms.ui.S3->setVisible(false);
	if (module->numchn > 4) fms.ui.S4->setVisible(true); else fms.ui.S4->setVisible(false);
	if (module->numchn > 5) fms.ui.S5->setVisible(true); else fms.ui.S5->setVisible(false);
	if (module->numchn > 6) fms.ui.S6->setVisible(true); else fms.ui.S6->setVisible(false);
	if (module->numchn > 7) fms.ui.S7->setVisible(true); else fms.ui.S7->setVisible(false);
	if (module->numchn > 8) fms.ui.S8->setVisible(true); else fms.ui.S8->setVisible(false);
	if (module->numchn > 9) fms.ui.S9->setVisible(true); else fms.ui.S9->setVisible(false);
	if (module->numchn > 10) fms.ui.S10->setVisible(true); else fms.ui.S10->setVisible(false);
	if (module->numchn > 11) fms.ui.S11->setVisible(true); else fms.ui.S11->setVisible(false);
	if (module->numchn > 12) fms.ui.S12->setVisible(true); else fms.ui.S12->setVisible(false);
	if (module->numchn > 13) fms.ui.S13->setVisible(true); else fms.ui.S13->setVisible(false);
	if (module->numchn > 14) fms.ui.S14->setVisible(true); else fms.ui.S14->setVisible(false);
	if (module->numchn > 15) fms.ui.S15->setVisible(true); else fms.ui.S15->setVisible(false);
	if (module->numchn > 16) fms.ui.S16->setVisible(true); else fms.ui.S16->setVisible(false);
	if (module->numchn > 17) fms.ui.S17->setVisible(true); else fms.ui.S17->setVisible(false);
	if (module->numchn > 18) fms.ui.S18->setVisible(true); else fms.ui.S18->setVisible(false);
	if (module->numchn > 19) fms.ui.S19->setVisible(true); else fms.ui.S19->setVisible(false);
	if (module->numchn > 20) fms.ui.S20->setVisible(true); else fms.ui.S20->setVisible(false);
	if (module->numchn > 22) fms.ui.S21->setVisible(true); else fms.ui.S21->setVisible(false);
	if (module->numchn > 22) fms.ui.S22->setVisible(true); else fms.ui.S22->setVisible(false);
	if (module->numchn > 23) fms.ui.S23->setVisible(true); else fms.ui.S23->setVisible(false);
	if (module->numchn > 24) fms.ui.S24->setVisible(true); else fms.ui.S24->setVisible(false);
	if (module->numchn > 25) fms.ui.S25->setVisible(true); else fms.ui.S25->setVisible(false);
	if (module->numchn > 26) fms.ui.S26->setVisible(true); else fms.ui.S26->setVisible(false);
	if (module->numchn > 27) fms.ui.S27->setVisible(true); else fms.ui.S27->setVisible(false);
	if (module->numchn > 28) fms.ui.S28->setVisible(true); else fms.ui.S28->setVisible(false);
	if (module->numchn > 29) fms.ui.S29->setVisible(true); else fms.ui.S29->setVisible(false);
}

void FormMMSlider::closeEvent(QCloseEvent*)
{
	setParent(NULL);
}
