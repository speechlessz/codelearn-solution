/**
 * Lời giải từ bạn fsoft_namnd28
 */

function waitingDays(a) {
	let sum = 0;
	a = a.sort((a, b) => a-b);	
	for (let i = 0; i < a.length; i = i+ 2) {
		sum = sum + ( a[i+1] - a[i]);
	}
	return sum;
}