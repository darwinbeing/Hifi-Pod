/**
 * struct tsc_data	Touchscreen wire configuration
 * @wires:		Wires refer to application modes
 *			i.e. 4/5/8 wire touchscreen support
 *			on the platform
 * @analog_input:	Analog inputs refer to the order in which the
 *			connections are made to the AFE. If the connections
 *			are as : XPUL = AN0,XNUR = AN1,YPLL = AN2,
 *			YNLR = AN3, then this variable is set to 1.
 *			Else if the connections are as :
 *			XPUL = AN0,YPLL = AN1,XNUR = AN2,
 *			YNLR = AN3, then set this variable to
 *			0.
 * @x_plate_resistance:	X plate resistance.
 */

struct tsc_data {
	int wires;
	u16 x_min, x_max;
	u16 y_min, y_max;
	int analog_input;
	int x_plate_resistance;
};
