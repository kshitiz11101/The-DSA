public class QueueUsingArray {

    private int[] array;
    private int front;
    private int rear;

    public QueueUsingArray(int size) {
        array = new int[size];
        front = 0;
        rear = -1;
    }

    public void enqueue(int item) {
        if (rear == array.length - 1) {
            System.out.println("Queue is full.");
        } else {
            System.out.println("Element enqueued in the queue " + item);
            rear++;
            array[rear] = item;
        }
    }

    public int dequeue() {
        if (front > rear) {
            System.out.println("Queue is empty.");
            return -1;
        } else {

            int item = array[front];
            front++;
            System.out.println("Element dequeued from the queue " + item);
            return item;
        }
    }

    public int peek() {
        if (front > rear) {
            System.out.println("Queue is empty.");
            return -1;
        } else {
            System.out.println("Peek element is " + array[front]);
            return array[front];
        }
    }

    public boolean isEmpty() {
        return (front > rear);
    }

    public static void main(String[] args) {
        QueueUsingArray q = new QueueUsingArray(5);
        q.enqueue(5);
        q.enqueue(12);
        q.enqueue(15);
        q.dequeue();
        q.peek();
    }
}
