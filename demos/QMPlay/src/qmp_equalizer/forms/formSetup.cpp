void FormSetup::showOpcje()
{
	if ( inSW )
	{
		fs.setParent(EqW);
		fs.setWindowFlags(Qt::Widget);
		fs.move(0,0);
		fs.resize( fs.minimumSize() );
		fs.ui.swB->setShortcut( QKeySequence() );
	}
	else
	{
		fs.setParent(NULL);
		fs.setWindowFlags(Qt::Window);
		fs.setGeometry(eqgeo);
		fs.ui.swB->setShortcut( QKeySequence("ESC") );
	}
	fs.show();
}

void FormSetup::_timEq()
{
	timEq.stop();
	if ( sw )
	{
		if ( QLib->inDock() != this )
			swB();
		sw = 0;
	}
	else
	{
		ui.swB->setChecked(false);
		swB();
	}
}

void FormSetup::closeEvent(QCloseEvent*)
{
	timEq.start( 10 );
}

void FormSetup::_glW()
{
	glW = ui.glW->isChecked();

	if ( glW )
	{
		ui.glF->show();
		Vis.setParent( fs.ui.glF );
		Vis.move(2,2);
		Vis.resize( ui.glF->maximumSize().width()-5, ui.glF->maximumSize().height()-5 );
		Vis.show();
		fs.setMinimumSize( fs.minimumSize().width(), 295 );
		fs.setMaximumSize( fs.maximumSize().width(), 295 );
	}
	else
	{
		Vis.close();
		ui.glF->hide();
		fs.setMinimumSize( fs.minimumSize().width(), 212 );
		fs.setMaximumSize( fs.maximumSize().width(), 212 );
	}
}

void FormSetup::Init()
{
	if ( inSW )
		ui.swB->setChecked( false );
	else
		ui.swB->setChecked( true );
	sw = 1;

	fs.ui.enabledB->setChecked( Enabled );
	fs.ui.glW->setChecked( glW );

	ApplyBands();

	Vis.setAutoFillBackground(1);
	_glW();
}

void FormSetup::enabledB()
{
	Enabled = fs.ui.enabledB->isChecked();
	if ( !Enabled && !doing )
		closeEff();
}

void FormSetup::swB()
{
	if ( ui.swB->isChecked() )
	{
		inSW = false;
		showOpcje();
	}
	else
	{
		if ( QLib->inDock() == this )
		{
			noShow = true;
			QLib->dock(NULL,0,NULL);
			inSW = true;
			showOpcje();
		}
		else
		{
			if ( !inSW && !sw )
				eqgeo = fs.geometry();
			inSW = true;
			showOpcje();
		}
	}
}

struct point
{
	double y;
};

void compute_intervals(int *, int , int );
double blend(int , int , int *, double);
void compute_point(int*, int, int, double, point *, point *);

void bspline(int n, int t, point *control, point *output, int num_output)
{
	int *u;
	double increment,interval;
	point calcxyz;
	int output_index;

	u=new int[n+t+1];
	compute_intervals(u, n, t);

	increment=(double) (n-t+2)/(num_output-1);  // how much parameter goes up each time
	interval=0;

	for (output_index=0; output_index<num_output-1; output_index++)
	{
		compute_point(u, n, t, interval, control, &calcxyz);
		output[output_index].y = calcxyz.y;
		interval=interval+increment;  // increment our parameter
	}
	output[num_output-1].y=control[n].y;

	delete u;
}

double blend(int k, int t, int *u, double v)  // calculate the blending value
{
	double value;

	if (t==1)               // base case for the recursion
	{
		if ((u[k]<=v) && (v<u[k+1]))
			value=1;
		else
			value=0;
	}
	else
	{
		if ((u[k+t-1]==u[k]) && (u[k+t]==u[k+1]))  // check for divide by zero
			value = 0;
		else
			if (u[k+t-1]==u[k]) // if a term's denominator is zero,use just the other
				value = (u[k+t] - v) / (u[k+t] - u[k+1]) * blend(k+1, t-1, u, v);
		else
			if (u[k+t]==u[k+1])
				value = (v - u[k]) / (u[k+t-1] - u[k]) * blend(k, t-1, u, v);
		else
			value = (v - u[k]) / (u[k+t-1] - u[k]) * blend(k, t-1, u, v) +
					(u[k+t] - v) / (u[k+t] - u[k+1]) * blend(k+1, t-1, u, v);
	}
	return value;
}

void compute_intervals(int *u, int n, int t)   // figure out the knots
{
	int j;

	for (j=0; j<=n+t; j++)
	{
		if (j<t)
			u[j]=0;
		else
			if ((t<=j) && (j<=n))
				u[j]=j-t+1;
		else
			if (j>n)
				u[j]=n-t+2;  // if n-t=-2 then we're screwed, everything goes to 0
	}
}

void compute_point(int *u, int n, int t, double v, point *control, point *output)
{
	int k;
	double temp;

  // initialize the variables that will hold our outputted point
	output->y=0;

	for (k=0; k<=n; k++)
	{
		temp = blend(k,t,u,v);  // same blend is used for each dimension coordinate
		output->y = output->y + (control[k]).y * temp;
	}
}

void FormSetup::ApplyBands()
{
	ui.sl0->setValue( valEq[0] );
	ui.sl1->setValue( valEq[1] );
	ui.sl2->setValue( valEq[2] );
	ui.sl3->setValue( valEq[3] );
	ui.sl4->setValue( valEq[4] );
	ui.sl5->setValue( valEq[5] );
	ui.sl6->setValue( valEq[6] );
	ui.sl7->setValue( valEq[7] );
	ui.sl8->setValue( valEq[8] );

	mn = valEq[0] /*/ 100.0*/ * 0.000009765625;

	int n(24),i(0);

	point *pts = new point[n+1];

	pts[0].y=valEq[1];
	pts[1].y=valEq[2];
	pts[2].y=valEq[3];
	for ( i = 3 ; i < 5 ; i++ )
		pts[i].y=valEq[4];
	for ( i = 5 ; i < 7 ; i++ )
		pts[i].y=valEq[5];
	for ( i = 7 ; i < 10 ; i++ )
		pts[i].y=valEq[6];
	for ( i = 10 ; i < 13 ; i++ )
		pts[i].y=valEq[7];
	for ( i = 13 ; i < 25 ; i++ )
		pts[i].y=valEq[8];

	point *out_pts = new point[len/2];
	bspline(n, 3, pts, out_pts, len/2);
	for ( int i = 0 ; i < len/2 ; i++ )
		filterFunc[i] = out_pts[i].y/100.;
	delete out_pts;
	delete pts;

	if ( glW )
		Vis.repaint();
}

void FormSetup::upB()
{
	for ( int i = 1 ; i < bands ; i++ )
		valEq[i] = 200;
	ApplyBands();
}

void FormSetup::dwnB()
{
	for ( int i = 1 ; i < bands ; i++ )
		valEq[i] = 50;
	ApplyBands();
}

void FormSetup::clrB()
{
	valEq[0] = ( ui.sl0->maximum() + ui.sl0->minimum() ) / 2;
	for ( int i = 1 ; i < bands ; i++ )
		valEq[i] = 100;
	ApplyBands();
}

void FormSetup::sl0()
{
	valEq[0] = ui.sl0->value();
	ApplyBands();
}
void FormSetup::sl1()
{
	valEq[1] = ui.sl1->value();
	ApplyBands();
}
void FormSetup::sl2()
{
	valEq[2] = ui.sl2->value();
	ApplyBands();
}
void FormSetup::sl3()
{
	valEq[3] = ui.sl3->value();
	ApplyBands();
}
void FormSetup::sl4()
{
	valEq[4] = ui.sl4->value();
	ApplyBands();
}
void FormSetup::sl5()
{
	valEq[5] = ui.sl5->value();
	ApplyBands();
}
void FormSetup::sl6()
{
	valEq[6] = ui.sl6->value();
	ApplyBands();
}
void FormSetup::sl7()
{
	valEq[7] = ui.sl7->value();
	ApplyBands();
}
void FormSetup::sl8()
{
	valEq[8] = ui.sl8->value();
	ApplyBands();
}

#include <QKeyEvent>
QString txt;
void FormSetup::keyPressEvent( QKeyEvent* e )
{
	if ( !frq )
	{
		txt += e->text();
		if ( ( e->text() != "f" && txt.length() == 1 ) || ( e->text() != "r" && txt.length() == 2 ) || ( e->text() != "e" && txt.length() == 3 ) || ( e->text() != "q" && txt.length() == 4 ) || ( e->text() != "o" && txt.length() == 5 ) || ( e->text() != "n" && txt.length() == 6 ) )
			txt = "";

		if ( txt == "freqon" )
		{
			invert = true;
			mode = 0;
			frq = true;
			txt = "";
		}
		else
			frq = false;
	}
	else
	{
		if ( e->text() == "0" || e->text() == "1" || e->text() == "2" || e->text() == "3" || e->text() == "4" || e->text() == "5" || e->text() == "6" || e->text() == "7" )
		{
			mode = e->text().toInt();
			txt = "";
			return;
		}

		if ( e->text() == "i" )
		{
			invert = !invert;
			txt = "";
			return;
		}

		txt += e->text();
		if ( ( e->text() != "f" && txt.length() == 1 ) || ( e->text() != "r" && txt.length() == 2 ) || ( e->text() != "e" && txt.length() == 3 ) || ( e->text() != "q" && txt.length() == 4 ) || ( e->text() != "o" && txt.length() == 5 ) || ( e->text() != "f" && txt.length() == 6 ) || ( e->text() != "f" && txt.length() == 7 ) )
			txt = "";

		if ( txt == "freqoff" )
		{
			invert = true;
			frq = false;
			txt = "";
		}
	}
}
