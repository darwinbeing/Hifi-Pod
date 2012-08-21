static GLfloat y_angle = 45.0, y_speed = 0.5;
static GLfloat x_angle = 20.0, x_speed = 0.0;
static GLfloat z_angle = 0.0, z_speed = 0.0;
static GLfloat heights[16][16], scale;

static void draw_rectangle(GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2, GLfloat z2)
{
	if(y1 == y2)
	{
		glVertex3f(x1, y1, z1);
		glVertex3f(x2, y1, z1);
		glVertex3f(x2, y2, z2);

		glVertex3f(x2, y2, z2);
		glVertex3f(x1, y2, z2);
		glVertex3f(x1, y1, z1);
	}
	else
	{
		glVertex3f(x1, y1, z1);
		glVertex3f(x2, y1, z2);
		glVertex3f(x2, y2, z2);

		glVertex3f(x2, y2, z2);
		glVertex3f(x1, y2, z1);
		glVertex3f(x1, y1, z1);
	}
}

static void draw_bar(GLfloat x_offset, GLfloat z_offset, GLfloat height, GLfloat red, GLfloat green, GLfloat blue )
{
	GLfloat width = 0.1;

	glColor3f(red,green,blue);
	draw_rectangle(x_offset, height, z_offset, x_offset + width, height, z_offset + 0.1);
	draw_rectangle(x_offset, 0.0, z_offset, x_offset + width, 0.0, z_offset + 0.1);

	glColor3f(0.5 * red, 0.5 * green, 0.5 * blue);
	draw_rectangle(x_offset, 0.0, z_offset + 0.1, x_offset + width, height, z_offset + 0.1);
	draw_rectangle(x_offset, 0.0, z_offset, x_offset + width, height, z_offset );

	glColor3f(0.25 * red, 0.25 * green, 0.25 * blue);
	draw_rectangle(x_offset, 0.0, z_offset , x_offset, height, z_offset + 0.1);
	draw_rectangle(x_offset + width, 0.0, z_offset , x_offset + width, height, z_offset + 0.1);
}

static void draw_bars(void)
{
	int x,y;
	GLfloat x_offset, z_offset, r_base, b_base;

	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glTranslatef(0.0,-0.5,-5.0);
	glRotatef(x_angle,1.0,0.0,0.0);
	glRotatef(y_angle,0.0,1.0,0.0);
	glRotatef(z_angle,0.0,0.0,1.0);

	glBegin(GL_TRIANGLES);
	for(y = 0; y < 16; y++)
	{
		z_offset = -1.6 + ((15 - y) * 0.2);

		b_base = y * (1.0 / 15);
		r_base = 1.0 - b_base;

		for(x = 0; x < 16; x++)
		{
			x_offset = -1.6 + (x * 0.2);

			draw_bar(x_offset, z_offset, heights[y][x], r_base - (x * (r_base / 15.0)), x * (1.0 / 15), b_base);
		}
	}
	glEnd();

	glPopMatrix();
}

static void start_display(void)
{
	int x, y;

	for(x = 0; x < 16; x++)
		for(y = 0; y < 16; y++)
			heights[y][x] = 0.0;
	scale = 1.0 / log(256.0);

	x_speed = 0.0;
	y_speed = 0.5;
	z_speed = 0.0;
	x_angle = 20.0;
	y_angle = 45.0;
	z_angle = 0.0;
}

static void oglspectrum_render_freq(short data[256])
{
	int i,c;
	int y;
	GLfloat val;

	int xscale[] = {0, 1, 2, 3, 5, 7, 10, 14, 20, 28, 40, 54, 74, 101, 137, 187, 255};

	for(y = 15; y > 0; y--)
		for(i = 0; i < 16; i++)
			heights[y][i] = heights[y - 1][i];

	for(i = 0; i < 16 ; i++)
	{
		for(c = xscale[i], y = 0; c < xscale[i + 1]; c++)
		{
			if(data[c] > y)
				y = data[c];
		}
		y >>= 7;
		if(y > 0)
			val = (log(y) * scale);
		else
			val = 0;

		heights[0][i] = val;
	}
}
