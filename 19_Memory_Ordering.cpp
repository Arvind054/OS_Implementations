/*
 CPU may not execute the independent intructions in the same order they are written.
 But this thing can cause Problem in multithreaded environment. so to solve this problem
 we need Memeory Ordering. It is a way to tell the CPU that Do not reorder these operations.
*/

/*
atomic<int> x; uses memory_order_seq_cst.

Relaxed Ordering: Make this operation atomic, but don't enforce ordering with other memory accesses.

Acquire and Release: 
Acquire says:
Once I observe the released value, I must also observe everything that happened before it.

Release says:
Everything before this store must become visible before this store itself becomes visible.

data = 42;

ready.store(
    true,
    std::memory_order_release
);
while(
    !ready.load(
        std::memory_order_acquire))
{
}

cout << data;

*/