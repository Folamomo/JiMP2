//
// Created by igor on 19.03.18.
//

#include <lzma.h>
#include "SimpleForwardList.h"

ForwardList *CreateNode(int value){
    ForwardList *newlist = new  ForwardList;
    newlist->next= nullptr;
    newlist->value=value;
    return newlist;
}
void DestroyList(ForwardList *list){
    while(list!= nullptr){
        ForwardList* to_delete = list->next;
        delete list;
        list = to_delete;
    }
}

ForwardList *PushFront(ForwardList *list, int value){
    if (list != nullptr) {
        ForwardList *newlist = new ForwardList;
        newlist->next = list;
        newlist->value = value;
        return newlist;
    } else return nullptr;
}
void Append(ForwardList *list, ForwardList *tail){
    if (list != nullptr) {
        while (list->next != nullptr)
            list = list->next;
        list->next = tail;
    } else {
        list = tail;
    }
}