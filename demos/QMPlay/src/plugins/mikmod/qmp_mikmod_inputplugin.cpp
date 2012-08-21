#include "var.h"

#include "formMMSlider.h"
#include "formSplIns.h"
#include "formSetup.h"
#include "formMod.h"

FormMMSlider &fms = *new FormMMSlider;
FormSplIns &fsi = *new FormSplIns;
FormSetup &fs = *new FormSetup;
FormMod *fm = new FormMod;

#include "mikmod_pl.h"

#include "save.h"

#include "forms.cpp"
