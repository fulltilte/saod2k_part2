using System;
using System.Text.RegularExpressions;
using System.IO;
using System.Xml;
using System.Text;
using System.Collections.Generic;
using System.Linq;
using System.Xml.Linq;

namespace RegExpLab
{
    class Program
    {
        static void Main(string[] args)
        {
            var str = " фыидо, fjbld33- 2олт?";
            // task 1.a
            var re = new Regex(@"."); // ищем любой символ
            Mathing(str, re,"a");
            // task 1.b
            re = new Regex(@"\w+"); // ищем слова
            Mathing(str, re,"b");
            // task 1.c
            re = new Regex(@"\b[0-9]+\w+\b"); // ищем слова начинающиеся с цифры
            Mathing(str, re, "c");
            // task 1.d
            str = "фыидо, fjbld33- 2олт 2p2 f8f73?";
            re = new Regex(@"\b(\w+\d+)|(\d+\w+)|(\w+\d+\w+)\b"); // ищем слова в котрых есть хоть одна цифрв
            Mathing(str, re, "d");
            // task 1.e
            re = new Regex(@"\w+3\b"); // ищем слова с тройкой на конце
            Mathing(str, re, "e");
            // task 1.f
            re = new Regex(@"(\w)\1"); // ищем два раза повторившийся символ слова 
            Mathing(str, re, "f");
            // task 1.g
            re = new Regex(@"\b\w+(\w)\1|(\w)\2\w+\b"); // поиск слов с сдвоенными символами
            Mathing(str, re, "g");
            // task 1.h
            str = " фыидо, fjbld33- 2олт?";
            re = new Regex(@"(\W*)(\w+)(\W+)(\w+)(\W+)(\w+)(\W*)"); // делим текст на семь частей
            Console.WriteLine(re.Replace(str, "$1$4$3$2$5$6$7")); // меняем вторую и четретую часть местами fjbld33- <=> фыидо
            // task 1.i
            re = new Regex(@"\b[0-9a-zA-Z]+\b");//слова только с латинскими буквами и цифрами. 
            Mathing(str, re, "i");
            // task 1.j
            re = new Regex(@"\b[a-zA-Z]\w+|\w+[a-zA-Z]\w*\b"); // находит все слова в котрый есть хотя бы одна латинская буква
            Mathing(str, re, "j");
            // task 1.k
            string orig;
            try
            {
                using (StreamReader sr = new StreamReader("Dictionary.xml"))
                {
                    orig = sr.ReadToEnd();
                    Console.WriteLine(orig.Length);
                }

            }
            catch (Exception ex)
            {
                Console.WriteLine("Ошибка чтения файла: \"Dictionary.xml\"\n{0}", ex);
                return;
            }
            
            Task_l(orig, "l");
            // task 1.n
            re = new Regex(@"(?<tag1>[\w-]+)>\s*[А-Я]\s*</\k<tag1>");
            var trans = Task_n(orig, "n");
            var trans2 = Task_m(orig, "m");
            // check 1
            trans = Task_n(trans2, "n");

            var trans3 = Task_o(trans2, "o");
            var trans4 = Task_q(trans2, "q");

            //check 2 
            trans3 = Task_o(trans4, "o");

            try
            {
                using (StreamWriter sw = new StreamWriter("test.xml"))
                {
                    sw.Write(trans4);
                }
                Console.WriteLine("write complete");
            }
            catch (Exception ex)
            {
                Console.WriteLine("Ошибка сохранений в файл: \"{0}\"\n{1}", "test.xml", ex);
                return;
            }
            try
            {
                XmlDocument doc = new XmlDocument();
                doc.LoadXml(trans4);
                Console.WriteLine("xml load succes");
            }
            catch
            {
                Console.WriteLine("something wrong!(");
            }
            Console.Read();
        }
        private static void Mathing(string str, Regex re, string name = "test", bool isStrShow = true)
        {
            Console.WriteLine(" \n\rstart mathing " + name);
            if(isStrShow) Console.WriteLine("Text : "+str);
            MatchCollection mc = re.Matches(str);
            foreach (var m in mc)
                Console.WriteLine(m);
            Console.WriteLine("end mathing " +name);
        }
        private static void Task_l(string str, string name = "test") 
        {
            var re = new Regex(@"<(?<tag1>[\w-]+)>[^><]*</\k<tag1>>");
            Console.WriteLine(" \n\rstart mathing " + name);
            MatchCollection mc = re.Matches(str);
            var s = new StringBuilder();
            foreach (var m in mc)
                s.Append(m.ToString());
            re = new Regex(@"[\w-]+(?=>)");
            mc = re.Matches(s.ToString());
            var ls = new List<string>();
            foreach (var m in mc)
                ls.Add(m.ToString()); 
            ls = ls.Distinct().ToList();
            foreach (var m in ls)
                Console.WriteLine(m);
            
            Console.WriteLine("end mathing " + name);
        }
        private static string Task_n(string str, string name = "test")
        {
            var  re = new Regex(@"((?<tag2>[\w-]+)?<(?<tag1>(?!italic)[\w-]+)>\s*(?<l>[А-Я])\s*</\k<tag1>>(k\<tag2>)?)");
            Console.WriteLine(" \n\rstart mathing " + name);
            MatchCollection mc = re.Matches(str);
            var sb = new StringBuilder();
            foreach (var m in mc)
            {
                sb.Append(m.ToString());
                Console.WriteLine(m);
            }
            Console.WriteLine("end mathing " + name);
            return sb.ToString();
        }
        private static string Task_m(string str, string name = "test")
        {
            var re = new Regex(@"((?<tag2>[\w-]+)?<(?<tag1>(?!italic)[\w-]+)>\s*(?<l>[А-Я])\s*</\k<tag1>>(k\<tag2>)?)");
            Console.WriteLine(" \n\rstart mathing " + name);
            MatchCollection mc = re.Matches(str);
            var s = re.Replace(str, "<letter><bold>${l}</bold></letter>\n\r");
            Console.WriteLine("end mathing " + name);
            return s;
        }
        private static string Task_o(string str, string name = "test")
        {
            var re = new Regex(@"</bold></letter>\s*(?<useless><(?<tag1>(?!(main-word|mainword))[\w-]+)>\s*</\k<tag1>>)");
            Console.WriteLine(" \n\rstart mathing " + name);
            MatchCollection mc = re.Matches(str);
            var sb = new StringBuilder();
            foreach (var m in mc)
            {
                sb.Append(m.ToString());
                Console.WriteLine(m);
            }
            Console.WriteLine("end mathing " + name);
            return sb.ToString();
        }
        private static string Task_q(string str, string name = "test")
        {
            var re = new Regex(@"(?<uses></bold></letter>\s*)(?<useless><(?<tag1>(?!(main-word|mainword))[\w-]+)>\s*</\k<tag1>>)");
            Console.WriteLine(" \n\rstart mathing " + name);
            MatchCollection mc = re.Matches(str);
            var s = re.Replace(str, "${uses}");
            Console.WriteLine("end mathing " + name);
            return s;
        }
    }
}
