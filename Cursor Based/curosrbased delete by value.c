void deleteByValue(LIST *L, data, VH){
    LIST curr = *L;
    LIST prev = -1;

    while(curr != NULL && VH->H[curr].data != data){
        curr = VH->H[curr].next;
        prev = curr;
        }
    }

    if(curr != -1){
        if(prev == 1){
            //remove first element
            *L = VH->H[curr].next;
        }
        else{
            VH->H[prev].next = VH->H[curr].next;
            ???
        }
        
    }
    dealloc(VH, curr);
}

