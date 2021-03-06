//
//  ViewController.h
//  MacWindow
//
//  Created by 威化饼干 on 3/11/2018.
//  Copyright © 2018 威化饼干. All rights reserved.
//
#import <Cocoa/Cocoa.h>
#import "UICanvas.h"

#include "MacDrawer.h"
#include "../MathLab/ViewStruct.h"

using MathLab::ViewStruct;

@interface ViewController : NSViewController

@property
(retain) UICanvas *canvs ;

- (void) initialize;
- (void) run;
- (void) shutdown;

@end

