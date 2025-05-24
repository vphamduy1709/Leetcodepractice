## Intuition
Ý tưởng ban đầu khi bước vào cũng chỉ là viết hàm push sao cho dùng ``top->next = node`` mới và set lại top. Còn pop thì viết hàm là gán tạm top vào một node p sau đó cho top=top->next và free(p).

Nhìn qua có thể đơn giản như một bài stimulate stack bình thường nhưng cái khó ở bài này là phải conform theo constraint của leetcode là chỉ cho dùng hàm void để viết PUSH && POP --> Ta phải dùng pass by references và phải dùng hàm minStackCreate --> Không nên dùng biến global top vì nó đã trả về con trỏ `Minstack*`rồi.

## Approach
Như đề cập ở trên sẽ có 2 vấn đề chính ta cần giải quyết ở đây là:
a. Làm sao để pass by reference ở 2 hàm void Push && Pop
b. Sẽ sử dụng con trỏ chỉ vào đầu stack như nào để thay thế cho việc dùng global variable top.

## Cách giải quyết:

Tư duy thông thường nhất để xử hàm void sẽ là ta phải pass 1 con trỏ vào trong hàm chứ không phải pass giá trị thường.
a. Trong bài đang có sẵn con trỏ *Minstack rồi nhưng ta cần trả về con trỏ top nên pass vào 1 con trỏ đầu ra là 1 con trỏ thì đây chỉ là pass by value và chỉ thay đổi local copy --> Ta nghĩ ngay đến việc biến *Minstack thành con trỏ trỏ tới con trỏ top nghĩa là **top. Mà trong bài đang yêu cầu struct Minstack --> Ta sẽ để con trỏ top là nằm trong struct Minstack
```
typedef struct MinStack {
    node *top;
} MinStack;
```
Và để một struct nữa là node và struct này sẽ như ở trong linkedlists:

typedef struct Node{
    int val;
    struct Node* next;
}node;
Và giờ ta đã có một con trỏ loại Minstack* và chỉ tới con trỏ top loại node --> Đã có dạng **top và khi đó ta pass vào hàm kiểu PUSH như này:
```
void minStackPush(MinStack* obj, int val) {
    node *p = makenode(val);
    p->next =  obj->top;
    obj->top = p;
}
```
Thì nó sẽ là pass con trỏ chỉ tới con trỏ --> sẽ thay đổi con trỏ top của chúng ta theo kiểu pass reference luôn ==> Giải quyết vấn đề 1.

Với ý tưởng này nó cũng mô hình chung giúp ta giải quyết vấn đề 2 về top global variable luôn vì bây giờ ta đã có con trỏ trỏ Stack->top rồi và hoàn toàn có thể pass by reference và không cần dựa vào biến toàn cục nữa.
