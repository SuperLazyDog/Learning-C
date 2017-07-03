//
//  Queue.c
//  Basic Review
//
//  Created by 徐伟达 on 2017/6/29.
//  Copyright © 2017年 徐伟达. All rights reserved.
//

#include "Queue.h"

//---------------------------------------------------------------------------
//                               序列(Queue)
//---------------------------------------------------------------------------
//-------------------------------------------------------
//                     需要自定义的函数
//-------------------------------------------------------
//---------------------------------------------
//                  数据对比函数
//---------------------------------------------
Bool compareData_Queue(const Queue_Data *ldata, const Queue_Data *rdata) { //测试专用
    return *ldata == *rdata;
}

//---------------------------------------------
//                  输出格式
//---------------------------------------------
Bool showData_Queue(Queue_Data *data) { //测试专用
    if (data == NULL) {
        printf("nothing in queue\n");
        return false;
    }
    printf("data: %d\n", *data);
    return true;
}

//-------------------------------------------------------
//                     管理测试的函数
//-------------------------------------------------------
void queueTest() {
    int count;
    Capacity max = 100;
    Queue *sample = NULL;
    Queue_Data *i = (Queue_Data *)calloc((unsigned long)1, sizeof(Queue_Data));
    *i = 0;
    sample = initialize_Queue(sample, max);
    /*while (!isFull_Queue(sample)) {
        enque_Queue(sample, i);
        //showData_Queue(&sample->queueList[(sample->front + *i) % sample->max]);
        (*i)++;
    }*/
    for (count = 0; count < 10000; count++) {
        
            enque_Queue(sample, i);
            (*i)++;
        
    }
    showQueue(sample, showData_Queue);
    terminate_Queue(sample);
    printf("i = %d\n", *i);
    free(i);
}
//-------------------------------------------------------
//                       初始化
//-------------------------------------------------------
Queue *initialize_Queue(Queue *queue, Capacity max) { // 初始化堆
    if (queue == NULL) {
        queue = callocPro(queue, 1, sizeof(Queue_Data), GETSTR_MEMSET);
        if (queue == NULL) {
            return NULL;// 初始化序列内存失败
        }
    }
    queue->front = queue->rear = queue->num = 0;
    queue->queueList = NULL;
    queue->queueList = (Queue_Data *)callocPro(queue->queueList, (unsigned long)max, sizeof(Queue_Data), GETSTR_MEMSET);
    if (queue->queueList == NULL) {// 初始化序列失败
        queue->max = 0;
        return NULL;
    }
    queue->max = max;
    return queue;
}

//-------------------------------------------------------
//                       插入数据
//-------------------------------------------------------
Bool enque_Queue(Queue *queue, Queue_Data *data) {
    if (queue->num >= queue->max) {// 序列已满
        return false;
    }else {
        queue->num++;
        queue->queueList[queue->rear++] = *data;
        if (queue->rear >= queue->max) {
            queue->rear = 0;
        }
        return true;
    }
}

//-------------------------------------------------------
//                       取出数据
//-------------------------------------------------------
Bool deque_Queue(Queue *queue, Queue_Data *temp) {
    if (temp == NULL) {
        temp = (Queue_Data *)callocPro(temp, 1, sizeof(Queue_Data), GETSTR_MEMSET);
    }
    if (queue == NULL) {//queue不存在
        return false;
    }
    if (queue->num <= 0) {
        return false; //没有数据
    }else {
        queue->num--;
        *temp = queue->queueList[queue->front++];
        if (queue->front >= queue->max) {
            queue->front = 0;
        }
        return true;
    }
}

//-------------------------------------------------------
//                        Peek
//-------------------------------------------------------
Bool peek_at_Queue(const Queue *queue, Queue_Data *temp) {
    if (queue == NULL) {
        return false; //没有数据
    }
    if (temp == NULL) {
        temp = (Queue_Data *)callocPro(temp, (unsigned long)1, sizeof(Queue_Data), GETSTR_MEMSET);
        if (temp == NULL) {
            return false; //初始化暂存数据失败
        }
    }
    if (queue->num <= 0) {
        return false; //没有数据
    }
    *temp = queue->queueList[queue->front];
    return true;
}

//-------------------------------------------------------
//                        Clear
//-------------------------------------------------------
Bool clear_Queue(Queue *queue) {
    if (queue == NULL) {
        return false; //没有数据
    }
    queue->num = 0;
    queue->front = 0;
    queue->rear = 0;
    return true;
}

//-------------------------------------------------------
//                       获取容量
//-------------------------------------------------------
Capacity getCapacity_From_Queue(const Queue *queue) {
    if (queue == NULL) {
        return false; //没有数据
    }
    return queue->max;
}

//-------------------------------------------------------
//                      获取数据数
//-------------------------------------------------------
Size getCount_Of_Queue_Data(const Queue *queue) {
    if (queue == NULL) {
        return false; //没有数据
    }
    return queue->num;
}

//-------------------------------------------------------
//                       是否空
//-------------------------------------------------------
Bool isEmpty_Queue(const Queue *queue) {
    if (queue == NULL) {
        return false; //没有数据
    }
    return queue->num <= 0;
}

//-------------------------------------------------------
//                       是否满
//-------------------------------------------------------
Bool isFull_Queue(const Queue *queue) {
    if (queue == NULL) {
        return false; //没有数据
    }
    return queue->num >= queue->max;
}

//-------------------------------------------------------
//                       搜索数据
//-------------------------------------------------------
POINTER search_In_Queue(const Queue *queue, const Queue_Data *data,
                        Bool compareData_Queue(const Queue_Data *ldata, const Queue_Data *rdata)) {
    Capacity i;
    if (queue == NULL || data == NULL) {
        return false; //数据不存在
    }
    for(i = 0; i < queue->num; i++) {
        if (compareData_Queue(data, &queue->queueList[(i + queue->front) % queue->max])) {
            return i;
        }
    }
    return false;
}

//-------------------------------------------------------
//                        表示
//-------------------------------------------------------
Bool showQueue(const Queue *queue,  Bool showData_Queue(Queue_Data *data)) {
    int i;
    if (queue == NULL) {
        return false; //没有数据
    }
    for (i = 0; i < queue->num; i++) {
        //printf("%d\n", i);
        //printf("%p\n", queue->queueList);
        //printf("front %d\n rear %d\n num %d\n max %d\n",queue->front, queue->rear, queue->num, queue->max);
        showData_Queue(&queue->queueList[(queue->front + i) % queue->max]);
    }
    return true;
}

//-------------------------------------------------------
//                        收尾
//-------------------------------------------------------
Bool terminate_Queue(Queue *queue) {
    if (queue == NULL) {
        return false; //已经被消除
    }
    if (queue->queueList != NULL) {
        free(queue->queueList);
    }
    queue->front = queue->rear = queue->max = queue->num = 0;
    return true;
}


