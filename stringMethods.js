let myString = "Hello, World!";

console.log("1. Length:", myString.length);

console.log("2. To Uppercase:", myString.toUpperCase());

console.log("3. To Lowercase:", myString.toLowerCase());

console.log("4. Index Of 'World':", myString.indexOf("World"));

console.log("5. Last Index Of 'l':", myString.lastIndexOf("l"));

console.log("6. Slice(7, 12):", myString.slice(7, 12));

console.log("7. Substring(7, 12):", myString.substring(7, 12));

console.log("8. Substr(7, 5):", myString.substr(7, 5));

console.log("9. Replace 'World' with 'Universe':", myString.replace("World", "Universe"));

let additionalString = " Have a great day!";
console.log("10. Concatenation:", myString + additionalString);

let stringWithWhitespace = "   Trim me!   ";
console.log("11. Trim:", stringWithWhitespace.trim());

console.log("12. Character at index 7:", myString.charAt(7));

console.log("13. Unicode value at index 7:", myString.charCodeAt(7));

console.log("14. Split by comma:", myString.split(','));

console.log("15. Starts with 'Hello':", myString.startsWith("Hello"));

console.log("16. Ends with 'World!':", myString.endsWith("World!"));