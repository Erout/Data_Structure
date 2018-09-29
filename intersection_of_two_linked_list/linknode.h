//
//  linkNode.h
//  linkNode
//
//  Created by apple on 18/9/25.
//  Copyright © 2018年 apple. All rights reserved.
//

#ifndef linkNode_h
#define linkNode_h

 struct linkNode {
     int val;
     linkNode *next;
     linkNode(int x) : val(x), next(NULL) {}
 };

linkNode *getIntersectionNode(linkNode *headA, linkNode *headB);


#endif /* linkNode_h */
