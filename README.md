# מטלה 1 - גרפים (Classes and Namespaces) 
## Author
- [Imri Shai](https://github.com/ImriShai)
- Email: imrish149@gmail.com
##


במטלה זו יצרתי מחלקה שמייצגת גרף על ידי מטריצת שכנויות. למחלקה שדות נוספים המתארים את סוג הגרף, למשל לא מכוון, ממושקל וכו'. 

בנוסף יצרתי מחלקה של שיטות סטטיות עם אלגוריתמים בסיסיים על גרפים.

הגרף יכול להיות גרף מכוון ולא מכוון וגם גרף ממושקלת עם משקלים שליליים וללא. מטריצת השכנויות חייבת להיות מטריצה ריבועית.


המחלקה Graph מכילה את הפעולות `loadGraph` המקבלת מטריצת שכנויות וטוענת אותה לתוך הגרף ו-`printGraph` שמדפיסה את הייצוג של הגרף. בנוסף מכילה פעולות get שמאפשרות לקבל מידע על הגרף, כגון `isDirected` שמחזירה האם הגרף מכוון.

הקובץ `Algorithms.cpp` מכיל מימושים לאלגוריתמים על גרפים. ביניהם:

- `isConnected(g)` - האלגוריתם מקבל גרף ובודק האם הוא קשיר (קשיר חזק). אם כן יחזיר ערך אמת, אחרת שקר
- `shortestPath(g,start,end)` -                                                                  האלגוריתם מקבל גרף, קודקוד התחלה וקודקוד סיום ומחזיר את המסלול הקל ביותר (במקרה שהגרף לא ממושקל - הקצר ביותר) בין שני הקודקודים. במידה ואין מסלול כזה, האלגוריתם יחזיר הודעת שגיאה מתאימה
 
- `isContainsCycle(g)` - האלגוריתם מקבל גרף ובודק אם קיים בו מעגל. אם כן, יחזיר את המעגל עצמו, אם לא, יחזיר הודעת שגיאאה מתאימה
- `isBipartite(g)` - האלגוריתם מקבל גרף ומחזיר את החלוקה של הגרף לגרף דו-צדדי, אם קיימת. אם אי אפשר לחלק את הגרף, האלגוריתם יחזיר הודעה בהתאם.
- `negativeCycle(g)` - האלגוריתם מקבל גרף, ומחזיר האם קיים בו מעגל שלילי. במידה וקיים, יחזיר את המעגל עצמו, במידה ולא, יחזיר הודעה מתאימה

הקובץ `Demo.cpp` מכיל דוגמאות של קלטים ופלטים, בנוסף הקובץ `Test.cpp` מכיל בדיקה של מקרי קצה, ודוגמאות נוספות.
האלגוריתמים מבוססים על הרצאות ותרגולי הקורס אלגוריתמים 1 ועל ערכי הויקיפדיה המתאימים.

