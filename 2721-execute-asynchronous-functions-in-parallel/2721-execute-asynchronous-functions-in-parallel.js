var promiseAll = function(functions) {
  return new Promise((resolve, reject) => {
    const results = [];
    let resolvedCount = 0;
    let rejected = false;

    for (let i = 0; i < functions.length; i++) {
      functions[i]()
        .then(result => {
          if (!rejected) {
            results[i] = result;
            resolvedCount++;

            if (resolvedCount === functions.length) {
              resolve(results);
            }
          }
        })
        .catch(error => {
          if (!rejected) {
            rejected = true;
            reject(error);
          }
        });
    }
  });
};
