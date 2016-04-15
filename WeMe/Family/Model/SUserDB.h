//
//  SUserDB.h
//  SDatabase
//
//  Created by SunJiangting on 12-10-20.
//  Copyright (c) 2012年 sun. All rights reserved.
//

#import "SDBManager.h"
#import "ChatInfo.h"


@interface SUserDB : NSObject
{
    FMDatabase * _db;
}


/**
 * @brief 创建数据库
 */
- (NSString *) createDataBase;


/**
 * @brief 保存一条用户记录
 * 
 * @param user 需要保存的用户数据
 */
- (void)addUser:(ChatInfo *) chat;



/**
 * @brief 删除一条用户数据
 *
 * @param uid 需要删除的用户的id
 */
- (void) deleteUserWithId:(NSString *) uid;



/**
 * @brief 修改用户的信息
 *
 * @param user 需要修改的用户信息
 */
- (void)updataWithUser:(ChatInfo *) chat;




/**
 * @brief 模拟分页查找数据。取uid大于某个值以后的limit个数据
 *
 * @param uid 
 * @param limit 每页取多少个
 */
- (NSArray *)findWithlimit:(int)limit;


@end
