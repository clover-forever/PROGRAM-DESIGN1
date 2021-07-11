queue_t * queue_new(void)
{
    queue_t *q = malloc(sizeof(queue_t));
    if (!q) {
        return q;
    }
    
    q->head = NULL;
    q->tail = NULL;
    
    return q;
}//佇列的建構函式
void queue_delete(void *self)
{
    if (!self)
        return;
    
    node_t *curr = ((queue_t *) self)->head;
    while (curr) {
        node_t *temp = curr;
        curr = curr->next;
        free(temp);
    }
    
    free(self);
}//佇列的解構函式
bool queue_is_empty(const queue_t *self)
{
    assert(self);
    
    return !(self->head) ? true : false;
}//確認佇列是否為空
int queue_peek(const queue_t *self)
{
    assert(!queue_is_empty(self));
    
    return self->head->data;
}//檢視佇列頭端的資料
bool queue_enqueue(queue_t *self, int data)
{
    assert(self);

    node_t *node = node_new(data);
    if (!node) {
        return false;
    }
    
    if (!(self->head)) {
        self->head = node;
        self->tail = node;
        return true;
    }
    
    self->tail->next = node;
    node->prev = self->tail;
    self->tail = node;
    
    return true;
}//將資料放入佇列
static node_t * node_new(int data)
{
    node_t *node = malloc(sizeof(node_t));
    if (!node)
        return node;
    
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    
    return node;
}//
int queue_dequeue(queue_t *self)
{
    assert(!queue_is_empty(self));

    int popped = self->head->data;
    
    if (self->head == self->tail) {
        free(self->head);
        self->head = NULL;
        self->tail = NULL;
    }
    else {
        node_t *curr = self->head;
        self->head = curr->next;
        free(curr);
    }
    
    return popped;
}//將資料移出佇列