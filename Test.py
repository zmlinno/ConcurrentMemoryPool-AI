import tensorflow as tf
import time
import threading

def test_tensorflow_alloc(n, num_threads):
    def worker():
        ptrs = [None] * n
        for i in range(n):
            ptrs[i] = tf.random.normal([128], dtype=tf.float32)  # 分配128个float32
        for i in range(n):
            del ptrs[i]

    threads = []
    start = time.time()
    for _ in range(num_threads):
        t = threading.Thread(target=worker)
        threads.append(t)
        t.start()
    for t in threads:
        t.join()
    end = time.time()
    duration = (end - start) * 1000  # 转换为毫秒
    print(f"TensorFlow alloc/free time with {num_threads} threads: {duration:.2f}ms")

if __name__ == "__main__":
    n = 100000  # 每个线程分配和释放的次数
    num_threads = 8  # 线程数

    print("Testing TensorFlow allocator in multithreaded environment...")
    test_tensorflow_alloc(n, num_threads)
