var expect = function(val) {
 return {
    toBe: function (otherVal) {
      if (val !== otherVal) {
        throw new Error("Not Equal");
      }
      return true;
    },
    notToBe: function (otherVal) {
      if (val === otherVal) {
        throw new Error("Equal");
      }
      return true;
    },
  };
    
};