 /*
  QtCurve (C) Craig Drummond, 2003 - 2010 craig.p.drummond@googlemail.com

  ----

  This program is free software; you can redistribute it and/or
  modify it under the terms of the GNU General Public
  License version 2 as published by the Free Software Foundation.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; see the file COPYING.  If not, write to
  the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
  Boston, MA 02110-1301, USA.
 */

#define IS_BLACK(A) (0==(A).red() && 0==(A).green() && 0==(A).blue())

#define MENU_FILE_PREFIX   "menubar-"
#define STATUS_FILE_PREFIX "statusbar-"

static int qtcGetWindowBorderSize()
{
    return 24;
}

static void readConfig(Options *opts)
{
    /* Set hard-coded defaults... */
#ifndef __cplusplus
    int i;

    for(i=0; i<NUM_CUSTOM_GRAD; ++i)
        opts->customGradient[i]=0L;
    opts->customGradient[APPEARANCE_CUSTOM1]=malloc(sizeof(Gradient));
    opts->customGradient[APPEARANCE_CUSTOM2]=malloc(sizeof(Gradient));
    setupGradient(opts->customGradient[APPEARANCE_CUSTOM1], GB_3D,3,0.0,1.2,0.5,1.0,1.0,1.0);
    setupGradient(opts->customGradient[APPEARANCE_CUSTOM2], GB_3D,3,0.0,0.9,0.5,1.0,1.0,1.0);
#else
    // Setup titlebar gradients...
    setupGradient(&(opts->customGradient[APPEARANCE_CUSTOM1]), GB_3D,3,0.0,1.2,0.5,1.0,1.0,1.0);
    setupGradient(&(opts->customGradient[APPEARANCE_CUSTOM2]), GB_3D,3,0.0,0.9,0.5,1.0,1.0,1.0);
#endif
    opts->customShades[0]=1.16;
    opts->customShades[1]=1.07;
    opts->customShades[2]=0.9;
    opts->customShades[3]=0.78;
    opts->customShades[4]=0.84;
    opts->customShades[5]=0.75;
    opts->contrast=7;
    opts->passwordChar=0x25CF;
    opts->highlightFactor=DEFAULT_HIGHLIGHT_FACTOR;
    opts->crHighlight=DEFAULT_CR_HIGHLIGHT_FACTOR;
    opts->splitterHighlight=DEFAULT_SPLITTER_HIGHLIGHT_FACTOR;
    opts->crSize=CR_LARGE_SIZE;
    opts->menuDelay=DEFAULT_MENU_DELAY;
    opts->sliderWidth=DEFAULT_SLIDER_WIDTH;
    opts->selectionAppearance=APPEARANCE_HARSH_GRADIENT;
#if defined CONFIG_DIALOG || (defined QT_VERSION && (QT_VERSION >= 0x040000)) || !defined __cplusplus
    opts->round=ROUND_EXTRA;
    opts->fadeLines=true;
    opts->glowProgress=GLOW_NONE;
    opts->gtkButtonOrder=false;
#else
    opts->round=ROUND_FULL;
#endif
#ifdef __cplusplus
    opts->dwtAppearance=APPEARANCE_CUSTOM1;
#endif
#if !defined __cplusplus || (defined CONFIG_DIALOG && defined QT_VERSION && (QT_VERSION >= 0x040000))
    opts->reorderGtkButtons=false;
#endif
    opts->bgndImage.type=IMG_NONE;
    opts->menuBgndImage.type=IMG_NONE;
    opts->lighterPopupMenuBgnd=DEF_POPUPMENU_LIGHT_FACTOR;
    opts->tabBgnd=DEF_TAB_BGND;
    opts->animatedProgress=false;
    opts->stripedProgress=STRIPE_NONE;
    opts->sliderStyle=SLIDER_PLAIN;
    opts->highlightTab=false;
    opts->colorSelTab=0;
    opts->roundAllTabs=true;
    opts->tabMouseOver=TAB_MO_GLOW;
    opts->embolden=false;
    opts->bgndGrad=GT_HORIZ;
    opts->menuBgndGrad=GT_HORIZ;
    opts->appearance=APPEARANCE_SOFT_GRADIENT;
    opts->bgndAppearance=APPEARANCE_FLAT;
    opts->menuBgndAppearance=APPEARANCE_FLAT;
    opts->lvAppearance=APPEARANCE_BEVELLED;
    opts->tabAppearance=APPEARANCE_SOFT_GRADIENT;
    opts->activeTabAppearance=APPEARANCE_SOFT_GRADIENT;
    opts->sliderAppearance=APPEARANCE_SOFT_GRADIENT;
    opts->menubarAppearance=APPEARANCE_FLAT;
	 opts->menuitemAppearance=APPEARANCE_HARSH_GRADIENT; //zmiana
    opts->toolbarAppearance=APPEARANCE_FLAT;
    opts->progressAppearance=APPEARANCE_DULL_GLASS;
    opts->progressGrooveAppearance=APPEARANCE_INVERTED;
    opts->progressGrooveColor=ECOLOR_DARK;
    opts->grooveAppearance=APPEARANCE_INVERTED;
    opts->sunkenAppearance=APPEARANCE_SOFT_GRADIENT;
    opts->sbarBgndAppearance=APPEARANCE_FLAT;
    opts->sliderFill=APPEARANCE_GRADIENT;
    opts->defBtnIndicator=IND_GLOW;
    opts->sliderThumbs=LINE_FLAT;
    opts->handles=LINE_1DOT;
    opts->shadeSliders=SHADE_NONE;
    opts->shadeMenubars=SHADE_NONE;
    opts->shadeCheckRadio=SHADE_NONE;
    opts->sortedLv=SHADE_NONE;
    opts->toolbarBorders=TB_NONE;
    opts->toolbarSeparators=LINE_SUNKEN;
    opts->splitters=LINE_1DOT;
    opts->fixParentlessDialogs=false;
    opts->customMenuTextColor=false;
    opts->coloredMouseOver=MO_GLOW;
    opts->menubarMouseOver=true;
	 opts->useHighlightForMenu=true; //zmiana
    opts->shadeMenubarOnlyWhenActive=false;
    opts->thinnerMenuItems=false;
    opts->thinnerBtns=true;
    opts->scrollbarType=SCROLLBAR_KDE;
    opts->buttonEffect=EFFECT_SHADOW;
    opts->focus=FOCUS_LINE;
    opts->lvButton=false;
    opts->lvLines=LV_NONE;
    opts->drawStatusBarFrames=false;
    opts->fillSlider=true;
    opts->roundMbTopOnly=true;
    opts->borderMenuitems=false;
    opts->darkerBorders=false;
    opts->vArrows=true;
    opts->xCheck=false;
    opts->framelessGroupBoxes=true;
    opts->groupBoxLine=true;
    opts->colorMenubarMouseOver=true;
    opts->crButton=true;
    opts->crColor=SHADE_NONE;
    opts->smallRadio=true;
    opts->fillProgress=true;
    opts->comboSplitter=false;
    opts->highlightScrollViews=false;
    opts->etchEntry=false;
    opts->flatSbarButtons=true;
    opts->borderSbarGroove=true;
    opts->borderProgress=true;
    opts->popupBorder=true;
    opts->unifySpinBtns=false;
    opts->unifySpin=true;
    opts->unifyCombo=true;
    opts->borderTab=true;
    opts->borderInactiveTab=false;
    opts->thinSbarGroove=true;
    opts->colorSliderMouseOver=false;
    opts->menuIcons=true;
    opts->forceAlternateLvCols=false;
    opts->invertBotTab=true;
    opts->menubarHiding=HIDE_NONE;
    opts->statusbarHiding=HIDE_NONE;
    opts->boldProgress=true;
    opts->coloredTbarMo=false;
    opts->borderSelection=false;
    opts->square=SQUARE_NONE;
    opts->stripedSbar=false;
    opts->windowDrag=false;
    opts->titlebarBorder=true;
    opts->titlebarBlend=false;
    opts->colorTitlebarOnly=false;
#if defined CONFIG_DIALOG || (defined QT_VERSION && (QT_VERSION >= 0x040000))
    opts->stdBtnSizes=false;
    opts->titlebarButtons=TITLEBAR_BUTTON_ROUND|TITLEBAR_BUTTON_HOVER_SYMBOL;
    opts->titlebarIcon=TITLEBAR_ICON_NEXT_TO_TITLE;
#endif
    opts->menuStripe=SHADE_NONE;
    opts->menuStripeAppearance=APPEARANCE_DARK_INVERTED;
    opts->shading=SHADING_HSL;
    opts->gtkScrollViews=true;
    opts->comboBtn=SHADE_NONE;
    opts->doubleGtkComboArrow=true;
    opts->stdSidebarButtons=false;
    opts->toolbarTabs=false;
#ifdef __cplusplus
    opts->gtkComboMenus=false;
    opts->customMenubarsColor.setRgb(0, 0, 0);
    opts->customSlidersColor.setRgb(0, 0, 0);
    opts->customMenuNormTextColor.setRgb(0, 0, 0);
    opts->customMenuSelTextColor.setRgb(0, 0, 0);
    opts->customCheckRadioColor.setRgb(0, 0, 0);
    opts->customComboBtnColor.setRgb(0, 0, 0);
    opts->customMenuStripeColor.setRgb(0, 0, 0);
    opts->titlebarAlignment=ALIGN_FULL_CENTER;
    opts->titlebarEffect=EFFECT_SHADOW;
    opts->centerTabText=false;
#if defined QT_VERSION && (QT_VERSION >= 0x040000)
    opts->xbar=false;
    opts->dwtSettings=DWT_BUTTONS_AS_PER_TITLEBAR|DWT_ROUND_TOP_ONLY;
    opts->menubarApps << "amarok" << "arora" << "kaffeine" << "kcalc" << "smplayer" << "VirtualBox";
    opts->statusbarApps << "kde";
    opts->useQtFileDialogApps << "googleearth-bin";
#endif
    opts->noDlgFixApps << "kate" << "plasma" << "plasma-desktop" << "plasma-netbook";
    opts->noMenuStripeApps << "gtk" << "soffice.bin";
#else
    opts->noBgndGradientApps=NULL;
    opts->noBgndImageApps=NULL;
    opts->noDlgFixApps=NULL;
    opts->noMenuStripeApps=g_strsplit("gtk",",", -1);
/*
    opts->setDialogButtonOrder=false;
*/
    opts->customMenubarsColor.red=opts->customMenubarsColor.green=opts->customMenubarsColor.blue=0;
    opts->customSlidersColor.red=opts->customSlidersColor.green=opts->customSlidersColor.blue=0;
    opts->customMenuNormTextColor.red=opts->customMenuNormTextColor.green=opts->customMenuNormTextColor.blue=0;
    opts->customMenuSelTextColor.red=opts->customMenuSelTextColor.green=opts->customMenuSelTextColor.blue=0;
    opts->customCheckRadioColor.red=opts->customCheckRadioColor.green=opts->customCheckRadioColor.blue=0;
    opts->customComboBtnColor.red=opts->customCheckRadioColor.green=opts->customCheckRadioColor.blue=0;
    opts->customMenuStripeColor.red=opts->customMenuStripeColor.green=opts->customMenuStripeColor.blue=0;
#endif

#if !defined __cplusplus || defined CONFIG_DIALOG
    opts->mapKdeIcons=true;
    opts->expanderHighlight=DEFAULT_EXPANDER_HIGHLIGHT_FACTOR;
#endif
    opts->titlebarAppearance=APPEARANCE_CUSTOM1;
    opts->inactiveTitlebarAppearance=APPEARANCE_CUSTOM1;
#ifdef __cplusplus
    opts->titlebarButtonAppearance=APPEARANCE_GRADIENT;
#endif

#if !defined CONFIG_DIALOG && defined QT_VERSION && (QT_VERSION < 0x040000)
    if(FOCUS_FILLED==opts->focus)
        opts->focus=FOCUS_FULL;
#endif

}
