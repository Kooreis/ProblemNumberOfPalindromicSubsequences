function countPalindromicSubsequences(str) {
    const n = str.length;
    const mod = Math.pow(10, 9) + 7;
    const dp = Array.from({ length: n }, () => Array(n).fill(0));
    const next = Array.from({ length: n }, () => Array(4).fill(0));
    const prev = Array.from({ length: n }, () => Array(4).fill(0));
    const aCharCode = 'a'.charCodeAt(0);
}