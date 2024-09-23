using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Runtime.Serialization.Formatters.Binary;
using System.Runtime.Serialization.Json;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace Serialization_and_Deserialization
{
    [Serializable]
    public class Person
    {
        public int Age { set; get; }
        public string Name { set; get; }

        public Person() { }

        public Person(string name, int age)
        {
            Age = age;
            Name = name;
        }
    }
    public class clsSerializationAndDeserialization
    {
        // XML Serialization

        private static XmlSerializer _XmlSerializer;
        public static void SerializationToXml(object O , string XmlFileName)
        {
             _XmlSerializer = new XmlSerializer(O.GetType());

            using (TextWriter writer = new StreamWriter(XmlFileName))
            {
                _XmlSerializer.Serialize(writer, O);
            }
        }

        public static object DeSerializationFromXml(object O, string XmlFileName)
        {
            using (TextReader reader = new StreamReader(XmlFileName))
            {
                 O = _XmlSerializer.Deserialize(reader);

                //Console.WriteLine($"The Name is {DeserializationPerson.Name} and its age is {DeserializationPerson.Age}");
            }

            return O;

        }

        //// Json Serialization

        private static DataContractJsonSerializer _JsonSerializer;

        public static void SerializationToJson(object O, string FileJsonName)
        {
            _JsonSerializer = new DataContractJsonSerializer(O.GetType());

            using (MemoryStream Stream = new MemoryStream())
            {
                _JsonSerializer.WriteObject(Stream, O);

                string Json = System.Text.Encoding.UTF8.GetString(Stream.ToArray());

                File.WriteAllText(FileJsonName,Json);

            }
        }

        public static object DeSerializationFromJson(object O, string FileJsonName)
        {
            using (FileStream stream = new FileStream(FileJsonName,FileMode.Open))
            {
                O = _JsonSerializer.ReadObject(stream);

                //Console.WriteLine($"The Name is {DeserializationPerson.Name} and its age is {DeserializationPerson.Age}");
            }

            return O;

        }

        //// Binary Serialization
        ///
        private static BinaryFormatter _BinaryFormatter;

        public static void SerializationToBinary(object O, string FileBinaryName)
        {
            _BinaryFormatter = new BinaryFormatter();

            using (FileStream stream = new FileStream(FileBinaryName, FileMode.Create))
            {
                _BinaryFormatter.Serialize(stream,O);
            }
        }

        public static object DeSerializationFromBinary(object O, string FileBinaryName)
        {
            using (FileStream stream = new FileStream(FileBinaryName, FileMode.Open))
            {
                O = _BinaryFormatter.Deserialize(stream);
            }

            return O;
        }


    }

}
