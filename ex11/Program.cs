using System;
using System.Text.RegularExpressions;
using System.IO;
using System.Xml;


namespace RegExpLab
{
    class Program
    {
        static void Main(string[] args)
        {
            string str = " фыидо, fjbld33- 2олт?";
            Console.WriteLine(str);
            Console.WriteLine("");

            //Regex re = new Regex(@".");               
            //a - по символам  (@"."означает поиск любого символа)

            //Regex re = new Regex(@"\w+");             
            //b - по словам  (@"\w+" означает поиск одного или более символов)

            //Regex re = new Regex(@"\b[0-9]+\w+\b");   
            //c - последнее слово  (в регулярном выражении указано, что нужно найти слово, которое начинается с одной или более цифр (\b[0-9]+), за которыми следует
            //одно или более буквенных символов (\w+), и заканчивается границей слова (\b))

            //Regex re = new Regex(@"\w*[0-9]+\w*");    
            //d - хотя бы 1 цифра

            //Regex re = new Regex(@"\w+3\b");          
            //e - 2e слово  (в @"\w+3\b" соответствует любому символу слова один или несколько раз (\w+), за которым сразу следует цыфра 3 и которая находится в конце слова (\b)

            //Regex re = new Regex(@"(\w)\1");          
            //f - 33  (В @"(\w)\1" круглые скобки создают группу, которая соответствует любому символу слова (\w) и сохраняет его в первой группе.
            //\1 - это обратная ссылка, которая соответствует тому же символу, который был подобран в первой группе.

            //Regex re = new Regex(@"\w*(\w)\1\w*");    
            //g - слова со сдвоенными символами

            //Regex re = new Regex(@"(\W*)(\w+)(\W+)(\w+)(\W+)(\w+)(\W*)"); 
            //h  
            //(\W*): группа, которая соответствует нулю или более несловесным символам (\W).
            //Цель этой группы - захватить все символы, не являющиеся словами, которые появляются перед первым словом в строке, и сохранить их положение в выходной строке.

            //(\w+): группа, которая соответствует одному или нескольким символам слова (\w).
            //Цель этой группы - захватить первое слово в строке и сохранить его позицию в выходной строке

            //(\W+): Это группа захвата, которая соответствует одному или нескольким символам, не являющимся словом (\W). каждой парой слов в строке, и сохранить их положение в выходной строке.

            //(\w+): Цель этой группы - захватить второе слово в строке и сохранить его позицию в выходной строке.

            //(\W+): Цель этой группы - захватить символы, не являющиеся словами, которые появляются между вторым и третьим словами в строке, и сохранить их положение в выходной строке.

            //(\w+): Цель этой группы - захватить третье слово в строке и сохранить его позицию в выходной строке.

            //(\W*): Цель этой группы - захватить все символы, не являющиеся словами, которые появляются после последнего слова в строке, и сохранить их положение в выходной строке.

            //Console.WriteLine(re.Replace(str, "$1$4$3$2$5$6$7"));            //Строка замены "$1$4$3$2$5$6$7" использует захваченные группы для перестановки слов
            //и несловесных символов в строке таким образом, чтобы в выходной строке второе и третье слова
            //поменялись местами, а позиции несловесных символов были сохранены. $1, $2, $3, $4, $5, $6, и $7
            //- это заполнители, которые ссылаются на текст, захваченный соответствующими группами захвата в регулярном выражении.

            //Regex re = new Regex(@"\b([a-zA-Z0-9]+)\b");                  
            //i - только латинские буквы и цыфры

            //Regex re = new Regex(@"\w*[a-zA]+\w+");                       
            //j - хотя бы 1 латинская буква

            string orig;                                                  //k
            try
            {
                using (StreamReader sr = new StreamReader("CreateDB.sql"))
                {
                    orig = sr.ReadToEnd();
                    //Console.WriteLine(orig.Length);
                }

            }
            catch (Exception ex)
            {
                Console.WriteLine("Ошибка чтения файла: \" CreateDB.sql\"\n{0}", ex);
                return;
            }

            //Regex re = new Regex(@"[(](?![0-9,]+)[^.]+[)]");              //l

            Regex re = new Regex(@"/((?!\d+(?:\s*,\s*\d+)*)[^)]+\))");

            //MatchCollection mc = re.Matches(orig);
            //foreach (var mm in mc)
            //    Console.WriteLine($"\n{mm}\n");

            //Console.WriteLine(mc.Count);

            //MatchCollection mc = re.Matches(str);
            //foreach (var m in mc)
            //    Console.WriteLine(m);

            string CreateDB = orig;
            {
                CreateDB = Regex.Replace(CreateDB, @"(GO)|(SET.+)", "");

                CreateDB = Regex.Replace(CreateDB, @"(CONSTRAINT\s\[.+\]\sPRIMARY\sKEY\sCLUSTERED\s)", "PRIMARY KEY");
                
                CreateDB = Regex.Replace(CreateDB, @"(\[.+\]\.)|([\[\]])|()", "");

                CreateDB = Regex.Replace(CreateDB, @"(WITH \(PAD_INDEX = OFF, STATISTICS_NORECOMPUTE = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS = ON, ALLOW_PAGE_LOCKS = ON\) ON .+)", "");
                 
                CreateDB = Regex.Replace(CreateDB, @"(IDENTITY\([0-9].[0-9]\))", "AUTO_INCREMENT");

                CreateDB = Regex.Replace(CreateDB, @"(timestamp NOT NULL)", "timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP");

                CreateDB = Regex.Replace(CreateDB, @"(PRIMARY\sKEY\sNONCLUSTERED\s)", "PRIMARY KEY");
                CreateDB = Regex.Replace(CreateDB, @"(UNIQUE\sNONCLUSTERED\s)", "UNIQUE KEY");

                CreateDB = Regex.Replace(CreateDB, @"\)\nPRIMARY\sKEY", "),\nPRIMARY KEY");
                CreateDB = Regex.Replace(CreateDB, @"\)\nUNIQUE\sKEY", "),\nUNIQUE KEY");
                 
                CreateDB = Regex.Replace(CreateDB, @"( ON PRIMARY TEXTIMAGE_ON PRIMARY)", ";");
                CreateDB = Regex.Replace(CreateDB, @"( ON PRIMARY)", ";");
                
                CreateDB = Regex.Replace(CreateDB, @"(uniqueidentifier)", "char(32)");
                
                CreateDB = Regex.Replace(CreateDB, @"(xml)|(ntext)|(nvarchar\(max\))", "text");

                CreateDB = Regex.Replace(CreateDB, @"(image)|(varbinary\(max\))", "BLOB");

                CreateDB = Regex.Replace(CreateDB, @"USE LockeyDB", "");//удаление той самой первой ошибки
            }

            try
            {
                using (StreamWriter sw = new StreamWriter("CreateDB_MySQL.sql"))
                {
                    sw.Write(CreateDB);
                    sw.Close();
                }
                Console.WriteLine("Class");
            }
            catch (Exception ex)
            {
                Console.WriteLine("Ошибка сохранений в файл: \"{0}\"\n{1}", "CreateDB_MySQL.sql", ex);
                return;
            }

            //Console.WriteLine(CreateDB);

            //MatchCollection mc2 = re.Matches(CreateDB);
            //foreach (var mm in mc2)
            //    Console.WriteLine($"\n{mm}\n");
        }
    }
}
