/**
 * Lời giải từ bạn MaiTheDung
 */
function minCostRepairingCar(a, b) {
    const arrLength = a.length
    let count = cost = 0
    let indexOfSmallest
    for (let i = 0; i < arrLength; i++)
      if (a[i] < b[i]) {
        cost += a[i]
        count += 1
      }
      else {
        cost += b[i]
        count += 2
      }
    if (count === arrLength) {
      indexOfSmallest = b.indexOf(Math.min(...b))
      cost += b[indexOfSmallest] - a[indexOfSmallest]
    }
    if (count === arrLength * 2) {
      indexOfSmallest = a.indexOf(Math.min(...a))
      cost += a[indexOfSmallest] - b[indexOfSmallest]
    }
    return cost
  }