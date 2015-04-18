using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace MergeSort
{
    class Program
    {
        // private static int[] Array;
        static void Main(string[] args)
        {
            int[] array1 = { 12, 11, 17, 16, 20, 45, 2, 9, 0, 5 };
            // int[] array2 = { 2, 3, 4, 5 };
            int[] aux = new int[array1.Length];
            // merge(array1, 2, 3, 2, ref aux);
            mergeSortArray(array1, 0, array1.Length - 1, ref aux);
            for (int i = 0; i < 10; i++)
                Console.Write(aux[i].ToString() + " ");
            //int[] array = { 1, 2, 4, 3, 0, 12, 11, 9 };
            Console.ReadKey();
        }

        private static void mergeSortArray(int[] array, int start, int end, ref int [] aux)
        {
            if (end <= 1 || start == end )
                return;
            int mid = (start + end) / 2;
            mergeSortArray(array, start, mid, ref aux);
            // Console.WriteLine("hellow  after ");
            mergeSortArray(array, mid + 1, end, ref aux);
           Console.WriteLine("start:" + start.ToString() + " and mid :" + mid.ToString() + " end : " + end.ToString());
            merge(array, start, mid, end - start, ref aux);
        }

        private static void merge(int[] array1, int i, int j, int end, ref int[] aux)
        {
            // Console.Write(" Len : " + array1.Length.ToString() + " and ; " + aux.Length.ToString());
            for (int a = 0, b = i, c = j; a < end ; a++)
            {
                if (b == j)
                {
                    // Console.Write(" inside : " + a.ToString() + " and : "  + c.ToString());
                    //if(c < aux.Length)
                    aux[a] = array1[c++];
                    continue;
                }
                if (c == end - 1)
                {
                    // if (b < aux.Length)
                    aux[a] = array1[b++];
                    continue;
                }
                // aux[a] = (array1[b] < array1[c]) ? array1[b++] : array1[c++];
            }
        }
    }
}
