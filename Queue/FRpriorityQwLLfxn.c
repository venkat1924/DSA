void pqinsert(QUEUE *q, int item){
    if(q->rear==SIZE-1)
        printf("Queue full \n");
    
    else{
        int pos=q->rear;
        q->rear=q->rear+1;
        while(pos!=0 && q->data[pos]>=item){
            q->data[pos]=q->data[pos+1];
            pos--;
        }
    q->data[pos+1]=item;
    if(q->front==-1)
        q->front=0;
    }
}

//needs double checking since gptuncle lapses on this fxn for some fucking reason
