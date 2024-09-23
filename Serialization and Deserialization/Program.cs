using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace Serialization_and_Deserialization
{



    public class Program
    {

        static void Main(string[] args)
        {
            /// XML Serialization
            Person person = new Person ("Bashar Abdulwahab", 23);
            string XmlFileName = "Person1.xml";

            clsSerializationAndDeserialization.SerializationToXml(person, XmlFileName);

            Person DeserializationXmlToPerson = null;

            DeserializationXmlToPerson = (Person)clsSerializationAndDeserialization.DeSerializationFromXml(DeserializationXmlToPerson, XmlFileName);

            Console.WriteLine($"The Name is {DeserializationXmlToPerson.Name} and its age is {DeserializationXmlToPerson.Age}");


            /////////////////////////////////////////////
            /// Json Serialization

            Person Person2 = new Person("Ali Saleh", 45);
            string JsonFileName = "Person2.json";

            clsSerializationAndDeserialization.SerializationToJson(Person2, JsonFileName);

            Person DeserializationJsonToPerson = null;

            DeserializationJsonToPerson = (Person)clsSerializationAndDeserialization.DeSerializationFromJson(DeserializationJsonToPerson, JsonFileName);

            Console.WriteLine($"The Name is {DeserializationJsonToPerson.Name} and its age is {DeserializationJsonToPerson.Age}");


            /////////////////////////////////////////////
            /// Binary Serialization
            /// 

            Person Person3 = new Person("Mohammed Khaled", 100);
            string BinaryFileName = "Person3.bin";

            clsSerializationAndDeserialization.SerializationToBinary(Person3, BinaryFileName);

            Person DeserializationBinaryToPerson = null;

            DeserializationBinaryToPerson = (Person)clsSerializationAndDeserialization.DeSerializationFromBinary(DeserializationBinaryToPerson, BinaryFileName);

            Console.WriteLine($"The Name is {DeserializationBinaryToPerson.Name} and its age is {DeserializationBinaryToPerson.Age}");




        }
    }
    
}
