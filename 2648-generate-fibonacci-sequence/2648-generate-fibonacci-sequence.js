var fibGenerator = function*(a = 0, b=1) {
    // yield the first number
    yield a;

    // recursively call fibGenerator and yield the entire generator function
    yield* fibGenerator(b, a+b);
};
