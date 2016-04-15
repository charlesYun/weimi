//
//  BaiduPanoramaView.h
//  BaiduPanoSDK
//
//  Created by bianheshan on 15/4/19.
//  Copyright (c) 2015年 baidu. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreMotion/CoreMotion.h>
#import "BaiduPanoImageOverlay.h"
#import "BaiduPanoLabelOverlay.h"

typedef enum : NSUInteger {
    ImageDefinitionHigh   = 5,// 高清图
    ImageDefinitionMiddle = 4,// 标准图
    ImageDefinitionLow    = 3,// 低清图
} ImageDefinition;

typedef enum : NSUInteger {
    EngineInitFailed      = 101,// 引擎初始化失败
    DescriptionLoadFailed = 102,// 引擎描述信息加载失败
    PanoramaLoadFailed    = 103,// 全景加载失败
} BaiduPanoError;

@class BaiduPanoramaView;
@protocol BaiduPanoramaViewDelegate <NSObject>
@optional

/**
 * @abstract 全景图将要加载
 * @param panoramaView 当前全景视图
 */
- (void)panoramaWillLoad:(BaiduPanoramaView *)panoramaView;

/**
 * @abstract 全景图加载完毕
 * @param panoramaView 当前全景视图
 * @param jsonStr 全景单点信息
 *
 */
- (void)panoramaDidLoad:(BaiduPanoramaView *)panoramaView descreption:(NSString *)jsonStr;

/**
 * @abstract 全景图加载失败
 * @param panoramaView 当前全景视图
 * @param error 加载失败的返回信息
 *
 */
- (void)panoramaLoadFailed:(BaiduPanoramaView *)panoramaView error:(NSError *)error;

/**
 * @abstract 全景图中的覆盖物点击事件
 * @param overlayId 覆盖物标识
 */
- (void)panoramaView:(BaiduPanoramaView *)panoramaView overlayClicked:(NSString *)overlayId;
@end

@interface BaiduPanoramaView : UIView

@property(assign, nonatomic) id<BaiduPanoramaViewDelegate> delegate;

#pragma mark - 获取全景

/**
 * @abstract 全景视图初始化
 * @param frame 视图的frame
 * @param key   百度LBS开放平台接入密钥
 */
- (id)initWithFrame:(CGRect)frame key:(NSString *)key;

/**
 * @abstract 全景视图初始化
 * @param frame 视图的frame
 */
- (id)initWithFrame:(CGRect)frame;

/**
 * @abstract 全景视图初始化
 * @param frame 视图的frame
 * @param mcX   百度墨卡托坐标x
 * @param mcY   百度墨卡托坐标y
 */
- (id)initWithFrame:(CGRect)frame mcX:(NSInteger)x mcY:(NSInteger)y;

/**
 * @abstract 切换全景场景至指定全景pid
 * @param pid 全景唯一id
 *
 */
- (void)setPanoramaWithPid:(NSString *)pid;

/**
 * @abstract 设定应用接入密钥
 * @param key 通过LBS开放平台创建应用获得
 *
 */
- (void)setPanoramaAccessKey:(NSString *)key;
/**
 * @abstract 切换全景场景至指定的地理坐标
 * @param lon 百度地理坐标经度
 * @param lat 百度地理坐标纬度
 */
- (void)setPanoramaWithLon:(double)lon lat:(double)lat;

/**
 * @abstract 切换全景场景至指定的百度墨卡托坐标
 * @param x 百度墨卡托投影坐标x
 * @param y 百度墨卡托投影坐标y
 */
- (void)setPanoramaWithX:(NSInteger)x Y:(NSInteger)y;

/**
 * @abstract 切换全景场景至指定的UID下
 * @param uid 百度全景uid
 */
- (void)setPanoramaWithUid:(NSString *)uid;

#pragma mark - 全景图属性设置以及获取
/**
 * @abstract 设置全景场景缩放级别
 * @param level 级别：1~5 缩放级别依次变大 默认值: 2
 *
 */
- (void)setPanoramaZoomLevel:(int)level;

/**
 * @abstract 设置全景场景使用图片级别
 * @param level 图片级别 清晰度:ImageDefinition，默认值:middle
 *
 */
- (void)setPanoramaImageLevel:(ImageDefinition)imageDefinition;

/**
 * @abstract 设置全景图的俯仰角
 * @param pitch 俯仰角, 室外环境:-90~15 度    默认值: 0 度  室内环境: -90~25 默认值 0 度
 */
- (void)setPanoramaPitch:(float)pitch;

/**
 * @abstract 设置全景图偏航角
 * @param heading 偏航角: 0~360 度  默认值: 0 度
 */
- (void)setPanoramaHeading:(float)heading;

/**
 * @abstract 设置道路剪头image
 * @param image UIImage对象
 */
- (void)setDirectionArrowImage:(UIImage *)image;

/**
 * @abstract 设置道路箭头指引,通过image的url
 * @param url 图片资源url
 */
- (void)setDirectionArrowByUrl:(NSString *)url;

/**
 * @abstract 是否显示道路箭头
 * @param isShow YES or NO
 */
- (void)showDirectionArrow:(BOOL) isShow;

/**
 * @abstract 获取当前全景缩放级别
 */
- (float)getPanoramaLevel;

/**
 * @abstract 获取当前全景俯仰角
 */
- (float)getPanoramaPitch;

/**
 * @abstract 获取当前全景朝向
 */
- (float)getPanoramaHeading;

#pragma mark - 全景图覆盖物
/**
 * @abstract 添加覆盖物
 * @param   overlay  抽象覆盖物
 */
- (void)addOverlay:(BaiduPanoOverlay *)overlay;

/**
 * @abstract 移除覆盖物
 * @param   overlayId
 */
- (void)removeOverlay:(NSString *)overlayId;

/**
 * @abstract 添加文字覆盖物
 * @param   overlayid   覆盖物id
 * @param   x   墨卡托坐标x
 * @param   y   墨卡托坐标y
 * @param   z   覆盖物高度z
 * @param   text    显示的文字
 */
- (void)addLabelOverlayById:(NSString *)overlayId
                          X:(NSInteger)x
                          Y:(NSInteger)y
                          Z:(NSInteger)z
                       text:(NSString *)text;

/**
 * @abstract 添加图片覆盖物
 * @param   overlayid   覆盖物id
 * @param   x   墨卡托坐标x
 * @param   y   墨卡托坐标y
 * @param   z   覆盖物盖度z
 * @param   image    显示的图片
 */
- (void)addImageOverlayById:(NSString *)overlayId
                          X:(NSInteger)x
                          Y:(NSInteger)y
                          Z:(NSInteger)z
                      image:(UIImage *)image;
@end