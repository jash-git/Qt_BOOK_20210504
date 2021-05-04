﻿#pragma once

#using <mscorlib.dll>
#using <System.dll>
#using <System.Data.dll>
#using <System.Xml.dll>

using namespace System::Security::Permissions;
[assembly:SecurityPermissionAttribute(SecurityAction::RequestMinimum, SkipVerification=false)];
// 
// 此源代码由 xsd 自动生成, Version=2.0.50727.3038。
// 
namespace schema {
    using namespace System;
    ref class NewDataSet;
    
    
    /// <summary>
///Represents a strongly typed in-memory cache of data.
///</summary>
    [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"2.0.0.0"), 
    System::Serializable, 
    System::ComponentModel::DesignerCategoryAttribute(L"code"), 
    System::ComponentModel::ToolboxItem(true), 
    System::Xml::Serialization::XmlSchemaProviderAttribute(L"GetTypedDataSetSchema"), 
    System::Xml::Serialization::XmlRootAttribute(L"NewDataSet"), 
    System::ComponentModel::Design::HelpKeywordAttribute(L"vs.data.DataSet")]
    public ref class NewDataSet : public ::System::Data::DataSet {
        public : ref class contactDataTable;
        public : ref class homeAddressDataTable;
        public : ref class workAddressDataTable;
        public : ref class contactRow;
        public : ref class homeAddressRow;
        public : ref class workAddressRow;
        public : ref class contactRowChangeEvent;
        public : ref class homeAddressRowChangeEvent;
        public : ref class workAddressRowChangeEvent;
        
        private: schema::NewDataSet::contactDataTable^  tablecontact;
        
        private: schema::NewDataSet::homeAddressDataTable^  tablehomeAddress;
        
        private: schema::NewDataSet::workAddressDataTable^  tableworkAddress;
        
        private: ::System::Data::DataRelation^  relationcontact_homeAddress;
        
        private: ::System::Data::DataRelation^  relationcontact_workAddress;
        
        private: ::System::Data::SchemaSerializationMode _schemaSerializationMode;
        
        public : delegate System::Void contactRowChangeEventHandler(::System::Object^  sender, schema::NewDataSet::contactRowChangeEvent^  e);
        
        public : delegate System::Void homeAddressRowChangeEventHandler(::System::Object^  sender, schema::NewDataSet::homeAddressRowChangeEvent^  e);
        
        public : delegate System::Void workAddressRowChangeEventHandler(::System::Object^  sender, schema::NewDataSet::workAddressRowChangeEvent^  e);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        NewDataSet();
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        NewDataSet(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context);
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::ComponentModel::Browsable(false), 
        System::ComponentModel::DesignerSerializationVisibility(::System::ComponentModel::DesignerSerializationVisibility::Content)]
        property schema::NewDataSet::contactDataTable^  contact {
            schema::NewDataSet::contactDataTable^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::ComponentModel::Browsable(false), 
        System::ComponentModel::DesignerSerializationVisibility(::System::ComponentModel::DesignerSerializationVisibility::Content)]
        property schema::NewDataSet::homeAddressDataTable^  homeAddress {
            schema::NewDataSet::homeAddressDataTable^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::ComponentModel::Browsable(false), 
        System::ComponentModel::DesignerSerializationVisibility(::System::ComponentModel::DesignerSerializationVisibility::Content)]
        property schema::NewDataSet::workAddressDataTable^  workAddress {
            schema::NewDataSet::workAddressDataTable^  get();
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::ComponentModel::BrowsableAttribute(true), 
        System::ComponentModel::DesignerSerializationVisibilityAttribute(::System::ComponentModel::DesignerSerializationVisibility::Visible)]
        virtual property ::System::Data::SchemaSerializationMode SchemaSerializationMode {
            ::System::Data::SchemaSerializationMode get() override;
            System::Void set(::System::Data::SchemaSerializationMode value) override;
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::ComponentModel::DesignerSerializationVisibilityAttribute(::System::ComponentModel::DesignerSerializationVisibility::Hidden)]
        property ::System::Data::DataTableCollection^  Tables {
            ::System::Data::DataTableCollection^  get() new;
        }
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
        System::ComponentModel::DesignerSerializationVisibilityAttribute(::System::ComponentModel::DesignerSerializationVisibility::Hidden)]
        property ::System::Data::DataRelationCollection^  Relations {
            ::System::Data::DataRelationCollection^  get() new;
        }
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        virtual ::System::Void InitializeDerivedDataSet() override;
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        virtual ::System::Data::DataSet^  Clone() override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        virtual ::System::Boolean ShouldSerializeTables() override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        virtual ::System::Boolean ShouldSerializeRelations() override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        virtual ::System::Void ReadXmlSerializable(::System::Xml::XmlReader^  reader) override;
        
        protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        virtual ::System::Xml::Schema::XmlSchema^  GetSchemaSerializable() override;
        
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        ::System::Void InitVars();
        
        internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        ::System::Void InitVars(::System::Boolean initTable);
        
        private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        ::System::Void InitClass();
        
        private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        ::System::Boolean ShouldSerializecontact();
        
        private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        ::System::Boolean ShouldSerializehomeAddress();
        
        private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        ::System::Boolean ShouldSerializeworkAddress();
        
        private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        ::System::Void SchemaChanged(::System::Object^  sender, ::System::ComponentModel::CollectionChangeEventArgs^  e);
        
        public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
        static ::System::Xml::Schema::XmlSchemaComplexType^  GetTypedDataSetSchema(::System::Xml::Schema::XmlSchemaSet^  xs);
        
        public : /// <summary>
///Represents the strongly named DataTable class.
///</summary>
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"2.0.0.0"), 
        System::Serializable, 
        System::Xml::Serialization::XmlSchemaProviderAttribute(L"GetTypedTableSchema")]
        ref class contactDataTable : public ::System::Data::DataTable, public ::System::Collections::IEnumerable {
            
            private: ::System::Data::DataColumn^  columngivenName;
            
            private: ::System::Data::DataColumn^  columnfamilyName;
            
            private: ::System::Data::DataColumn^  columnbirthdate;
            
            private: ::System::Data::DataColumn^  columncontact_Id;
            
            public: event schema::NewDataSet::contactRowChangeEventHandler^  contactRowChanging;
            
            public: event schema::NewDataSet::contactRowChangeEventHandler^  contactRowChanged;
            
            public: event schema::NewDataSet::contactRowChangeEventHandler^  contactRowDeleting;
            
            public: event schema::NewDataSet::contactRowChangeEventHandler^  contactRowDeleted;
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            contactDataTable();
            internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            contactDataTable(::System::Data::DataTable^  table);
            protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            contactDataTable(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context);
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            property ::System::Data::DataColumn^  givenNameColumn {
                ::System::Data::DataColumn^  get();
            }
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            property ::System::Data::DataColumn^  familyNameColumn {
                ::System::Data::DataColumn^  get();
            }
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            property ::System::Data::DataColumn^  birthdateColumn {
                ::System::Data::DataColumn^  get();
            }
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            property ::System::Data::DataColumn^  contact_IdColumn {
                ::System::Data::DataColumn^  get();
            }
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
            System::ComponentModel::Browsable(false)]
            property ::System::Int32 Count {
                ::System::Int32 get();
            }
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            property schema::NewDataSet::contactRow^  default [::System::Int32 ] {
                schema::NewDataSet::contactRow^  get(::System::Int32 index);
            }
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            ::System::Void AddcontactRow(schema::NewDataSet::contactRow^  row);
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            schema::NewDataSet::contactRow^  AddcontactRow(System::String^  givenName, System::String^  familyName, System::DateTime birthdate);
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            virtual ::System::Collections::IEnumerator^  GetEnumerator();
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            virtual ::System::Data::DataTable^  Clone() override;
            
            protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            virtual ::System::Data::DataTable^  CreateInstance() override;
            
            internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            ::System::Void InitVars();
            
            private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            ::System::Void InitClass();
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            schema::NewDataSet::contactRow^  NewcontactRow();
            
            protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            virtual ::System::Data::DataRow^  NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) override;
            
            protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            virtual ::System::Type^  GetRowType() override;
            
            protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            virtual ::System::Void OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) override;
            
            protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            virtual ::System::Void OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) override;
            
            protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            virtual ::System::Void OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) override;
            
            protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            virtual ::System::Void OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) override;
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            ::System::Void RemovecontactRow(schema::NewDataSet::contactRow^  row);
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            static ::System::Xml::Schema::XmlSchemaComplexType^  GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs);
        };
        
        public : /// <summary>
///Represents the strongly named DataTable class.
///</summary>
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"2.0.0.0"), 
        System::Serializable, 
        System::Xml::Serialization::XmlSchemaProviderAttribute(L"GetTypedTableSchema")]
        ref class homeAddressDataTable : public ::System::Data::DataTable, public ::System::Collections::IEnumerable {
            
            private: ::System::Data::DataColumn^  columnstreet;
            
            private: ::System::Data::DataColumn^  columnzipCode;
            
            private: ::System::Data::DataColumn^  columncity;
            
            private: ::System::Data::DataColumn^  columncountry;
            
            private: ::System::Data::DataColumn^  columncontact_Id;
            
            public: event schema::NewDataSet::homeAddressRowChangeEventHandler^  homeAddressRowChanging;
            
            public: event schema::NewDataSet::homeAddressRowChangeEventHandler^  homeAddressRowChanged;
            
            public: event schema::NewDataSet::homeAddressRowChangeEventHandler^  homeAddressRowDeleting;
            
            public: event schema::NewDataSet::homeAddressRowChangeEventHandler^  homeAddressRowDeleted;
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            homeAddressDataTable();
            internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            homeAddressDataTable(::System::Data::DataTable^  table);
            protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            homeAddressDataTable(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context);
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            property ::System::Data::DataColumn^  streetColumn {
                ::System::Data::DataColumn^  get();
            }
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            property ::System::Data::DataColumn^  zipCodeColumn {
                ::System::Data::DataColumn^  get();
            }
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            property ::System::Data::DataColumn^  cityColumn {
                ::System::Data::DataColumn^  get();
            }
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            property ::System::Data::DataColumn^  countryColumn {
                ::System::Data::DataColumn^  get();
            }
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            property ::System::Data::DataColumn^  contact_IdColumn {
                ::System::Data::DataColumn^  get();
            }
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
            System::ComponentModel::Browsable(false)]
            property ::System::Int32 Count {
                ::System::Int32 get();
            }
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            property schema::NewDataSet::homeAddressRow^  default [::System::Int32 ] {
                schema::NewDataSet::homeAddressRow^  get(::System::Int32 index);
            }
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            ::System::Void AddhomeAddressRow(schema::NewDataSet::homeAddressRow^  row);
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            schema::NewDataSet::homeAddressRow^  AddhomeAddressRow(System::String^  street, System::String^  zipCode, System::String^  city, 
                        System::String^  country, schema::NewDataSet::contactRow^  parentcontactRowBycontact_homeAddress);
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            virtual ::System::Collections::IEnumerator^  GetEnumerator();
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            virtual ::System::Data::DataTable^  Clone() override;
            
            protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            virtual ::System::Data::DataTable^  CreateInstance() override;
            
            internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            ::System::Void InitVars();
            
            private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            ::System::Void InitClass();
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            schema::NewDataSet::homeAddressRow^  NewhomeAddressRow();
            
            protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            virtual ::System::Data::DataRow^  NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) override;
            
            protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            virtual ::System::Type^  GetRowType() override;
            
            protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            virtual ::System::Void OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) override;
            
            protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            virtual ::System::Void OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) override;
            
            protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            virtual ::System::Void OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) override;
            
            protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            virtual ::System::Void OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) override;
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            ::System::Void RemovehomeAddressRow(schema::NewDataSet::homeAddressRow^  row);
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            static ::System::Xml::Schema::XmlSchemaComplexType^  GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs);
        };
        
        public : /// <summary>
///Represents the strongly named DataTable class.
///</summary>
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"2.0.0.0"), 
        System::Serializable, 
        System::Xml::Serialization::XmlSchemaProviderAttribute(L"GetTypedTableSchema")]
        ref class workAddressDataTable : public ::System::Data::DataTable, public ::System::Collections::IEnumerable {
            
            private: ::System::Data::DataColumn^  columnstreet;
            
            private: ::System::Data::DataColumn^  columnzipCode;
            
            private: ::System::Data::DataColumn^  columncity;
            
            private: ::System::Data::DataColumn^  columncountry;
            
            private: ::System::Data::DataColumn^  columncontact_Id;
            
            public: event schema::NewDataSet::workAddressRowChangeEventHandler^  workAddressRowChanging;
            
            public: event schema::NewDataSet::workAddressRowChangeEventHandler^  workAddressRowChanged;
            
            public: event schema::NewDataSet::workAddressRowChangeEventHandler^  workAddressRowDeleting;
            
            public: event schema::NewDataSet::workAddressRowChangeEventHandler^  workAddressRowDeleted;
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            workAddressDataTable();
            internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            workAddressDataTable(::System::Data::DataTable^  table);
            protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            workAddressDataTable(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context);
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            property ::System::Data::DataColumn^  streetColumn {
                ::System::Data::DataColumn^  get();
            }
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            property ::System::Data::DataColumn^  zipCodeColumn {
                ::System::Data::DataColumn^  get();
            }
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            property ::System::Data::DataColumn^  cityColumn {
                ::System::Data::DataColumn^  get();
            }
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            property ::System::Data::DataColumn^  countryColumn {
                ::System::Data::DataColumn^  get();
            }
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            property ::System::Data::DataColumn^  contact_IdColumn {
                ::System::Data::DataColumn^  get();
            }
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute, 
            System::ComponentModel::Browsable(false)]
            property ::System::Int32 Count {
                ::System::Int32 get();
            }
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            property schema::NewDataSet::workAddressRow^  default [::System::Int32 ] {
                schema::NewDataSet::workAddressRow^  get(::System::Int32 index);
            }
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            ::System::Void AddworkAddressRow(schema::NewDataSet::workAddressRow^  row);
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            schema::NewDataSet::workAddressRow^  AddworkAddressRow(System::String^  street, System::String^  zipCode, System::String^  city, 
                        System::String^  country, schema::NewDataSet::contactRow^  parentcontactRowBycontact_workAddress);
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            virtual ::System::Collections::IEnumerator^  GetEnumerator();
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            virtual ::System::Data::DataTable^  Clone() override;
            
            protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            virtual ::System::Data::DataTable^  CreateInstance() override;
            
            internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            ::System::Void InitVars();
            
            private: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            ::System::Void InitClass();
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            schema::NewDataSet::workAddressRow^  NewworkAddressRow();
            
            protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            virtual ::System::Data::DataRow^  NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) override;
            
            protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            virtual ::System::Type^  GetRowType() override;
            
            protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            virtual ::System::Void OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) override;
            
            protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            virtual ::System::Void OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) override;
            
            protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            virtual ::System::Void OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) override;
            
            protected: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            virtual ::System::Void OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) override;
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            ::System::Void RemoveworkAddressRow(schema::NewDataSet::workAddressRow^  row);
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            static ::System::Xml::Schema::XmlSchemaComplexType^  GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs);
        };
        
        public : /// <summary>
///Represents strongly named DataRow class.
///</summary>
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"2.0.0.0")]
        ref class contactRow : public ::System::Data::DataRow {
            
            private: schema::NewDataSet::contactDataTable^  tablecontact;
            
            internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            contactRow(::System::Data::DataRowBuilder^  rb);
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            property System::String^  givenName {
                System::String^  get();
                System::Void set(System::String^  value);
            }
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            property System::String^  familyName {
                System::String^  get();
                System::Void set(System::String^  value);
            }
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            property System::DateTime birthdate {
                System::DateTime get();
                System::Void set(System::DateTime value);
            }
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            property System::Int32 contact_Id {
                System::Int32 get();
                System::Void set(System::Int32 value);
            }
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            ::System::Boolean IsbirthdateNull();
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            ::System::Void SetbirthdateNull();
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            cli::array< schema::NewDataSet::homeAddressRow^  >^  GethomeAddressRows();
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            cli::array< schema::NewDataSet::workAddressRow^  >^  GetworkAddressRows();
        };
        
        public : /// <summary>
///Represents strongly named DataRow class.
///</summary>
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"2.0.0.0")]
        ref class homeAddressRow : public ::System::Data::DataRow {
            
            private: schema::NewDataSet::homeAddressDataTable^  tablehomeAddress;
            
            internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            homeAddressRow(::System::Data::DataRowBuilder^  rb);
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            property System::String^  street {
                System::String^  get();
                System::Void set(System::String^  value);
            }
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            property System::String^  zipCode {
                System::String^  get();
                System::Void set(System::String^  value);
            }
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            property System::String^  city {
                System::String^  get();
                System::Void set(System::String^  value);
            }
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            property System::String^  country {
                System::String^  get();
                System::Void set(System::String^  value);
            }
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            property System::Int32 contact_Id {
                System::Int32 get();
                System::Void set(System::Int32 value);
            }
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            property schema::NewDataSet::contactRow^  contactRow {
                schema::NewDataSet::contactRow^  get();
                System::Void set(schema::NewDataSet::contactRow^  value);
            }
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            ::System::Boolean Iscontact_IdNull();
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            ::System::Void Setcontact_IdNull();
        };
        
        public : /// <summary>
///Represents strongly named DataRow class.
///</summary>
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"2.0.0.0")]
        ref class workAddressRow : public ::System::Data::DataRow {
            
            private: schema::NewDataSet::workAddressDataTable^  tableworkAddress;
            
            internal: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            workAddressRow(::System::Data::DataRowBuilder^  rb);
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            property System::String^  street {
                System::String^  get();
                System::Void set(System::String^  value);
            }
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            property System::String^  zipCode {
                System::String^  get();
                System::Void set(System::String^  value);
            }
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            property System::String^  city {
                System::String^  get();
                System::Void set(System::String^  value);
            }
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            property System::String^  country {
                System::String^  get();
                System::Void set(System::String^  value);
            }
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            property System::Int32 contact_Id {
                System::Int32 get();
                System::Void set(System::Int32 value);
            }
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            property schema::NewDataSet::contactRow^  contactRow {
                schema::NewDataSet::contactRow^  get();
                System::Void set(schema::NewDataSet::contactRow^  value);
            }
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            ::System::Boolean Iscontact_IdNull();
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            ::System::Void Setcontact_IdNull();
        };
        
        public : /// <summary>
///Row event argument class
///</summary>
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"2.0.0.0")]
        ref class contactRowChangeEvent : public ::System::EventArgs {
            
            private: schema::NewDataSet::contactRow^  eventRow;
            
            private: ::System::Data::DataRowAction eventAction;
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            contactRowChangeEvent(schema::NewDataSet::contactRow^  row, ::System::Data::DataRowAction action);
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            property schema::NewDataSet::contactRow^  Row {
                schema::NewDataSet::contactRow^  get();
            }
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            property ::System::Data::DataRowAction Action {
                ::System::Data::DataRowAction get();
            }
        };
        
        public : /// <summary>
///Row event argument class
///</summary>
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"2.0.0.0")]
        ref class homeAddressRowChangeEvent : public ::System::EventArgs {
            
            private: schema::NewDataSet::homeAddressRow^  eventRow;
            
            private: ::System::Data::DataRowAction eventAction;
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            homeAddressRowChangeEvent(schema::NewDataSet::homeAddressRow^  row, ::System::Data::DataRowAction action);
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            property schema::NewDataSet::homeAddressRow^  Row {
                schema::NewDataSet::homeAddressRow^  get();
            }
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            property ::System::Data::DataRowAction Action {
                ::System::Data::DataRowAction get();
            }
        };
        
        public : /// <summary>
///Row event argument class
///</summary>
        [System::CodeDom::Compiler::GeneratedCodeAttribute(L"System.Data.Design.TypedDataSetGenerator", L"2.0.0.0")]
        ref class workAddressRowChangeEvent : public ::System::EventArgs {
            
            private: schema::NewDataSet::workAddressRow^  eventRow;
            
            private: ::System::Data::DataRowAction eventAction;
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            workAddressRowChangeEvent(schema::NewDataSet::workAddressRow^  row, ::System::Data::DataRowAction action);
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            property schema::NewDataSet::workAddressRow^  Row {
                schema::NewDataSet::workAddressRow^  get();
            }
            
            public: [System::Diagnostics::DebuggerNonUserCodeAttribute]
            property ::System::Data::DataRowAction Action {
                ::System::Data::DataRowAction get();
            }
        };
    };
}
namespace schema {
    
    
    inline NewDataSet::NewDataSet() {
        this->BeginInit();
        this->InitClass();
        ::System::ComponentModel::CollectionChangeEventHandler^  schemaChangedHandler = gcnew ::System::ComponentModel::CollectionChangeEventHandler(this, &schema::NewDataSet::SchemaChanged);
        __super::Tables->CollectionChanged += schemaChangedHandler;
        __super::Relations->CollectionChanged += schemaChangedHandler;
        this->EndInit();
    }
    
    inline NewDataSet::NewDataSet(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context) : 
            ::System::Data::DataSet(info, context, false) {
        if (this->IsBinarySerialized(info, context) == true) {
            this->InitVars(false);
            ::System::ComponentModel::CollectionChangeEventHandler^  schemaChangedHandler1 = gcnew ::System::ComponentModel::CollectionChangeEventHandler(this, &schema::NewDataSet::SchemaChanged);
            this->Tables->CollectionChanged += schemaChangedHandler1;
            this->Relations->CollectionChanged += schemaChangedHandler1;
            return;
        }
        ::System::String^  strSchema = (cli::safe_cast<::System::String^  >(info->GetValue(L"XmlSchema", ::System::String::typeid)));
        if (this->DetermineSchemaSerializationMode(info, context) == ::System::Data::SchemaSerializationMode::IncludeSchema) {
            ::System::Data::DataSet^  ds = (gcnew ::System::Data::DataSet());
            ds->ReadXmlSchema((gcnew ::System::Xml::XmlTextReader((gcnew ::System::IO::StringReader(strSchema)))));
            if (ds->Tables[L"contact"] != nullptr) {
                __super::Tables->Add((gcnew schema::NewDataSet::contactDataTable(ds->Tables[L"contact"])));
            }
            if (ds->Tables[L"homeAddress"] != nullptr) {
                __super::Tables->Add((gcnew schema::NewDataSet::homeAddressDataTable(ds->Tables[L"homeAddress"])));
            }
            if (ds->Tables[L"workAddress"] != nullptr) {
                __super::Tables->Add((gcnew schema::NewDataSet::workAddressDataTable(ds->Tables[L"workAddress"])));
            }
            this->DataSetName = ds->DataSetName;
            this->Prefix = ds->Prefix;
            this->Namespace = ds->Namespace;
            this->Locale = ds->Locale;
            this->CaseSensitive = ds->CaseSensitive;
            this->EnforceConstraints = ds->EnforceConstraints;
            this->Merge(ds, false, ::System::Data::MissingSchemaAction::Add);
            this->InitVars();
        }
        else {
            this->ReadXmlSchema((gcnew ::System::Xml::XmlTextReader((gcnew ::System::IO::StringReader(strSchema)))));
        }
        this->GetSerializationData(info, context);
        ::System::ComponentModel::CollectionChangeEventHandler^  schemaChangedHandler = gcnew ::System::ComponentModel::CollectionChangeEventHandler(this, &schema::NewDataSet::SchemaChanged);
        __super::Tables->CollectionChanged += schemaChangedHandler;
        this->Relations->CollectionChanged += schemaChangedHandler;
    }
    
    inline schema::NewDataSet::contactDataTable^  NewDataSet::contact::get() {
        return this->tablecontact;
    }
    
    inline schema::NewDataSet::homeAddressDataTable^  NewDataSet::homeAddress::get() {
        return this->tablehomeAddress;
    }
    
    inline schema::NewDataSet::workAddressDataTable^  NewDataSet::workAddress::get() {
        return this->tableworkAddress;
    }
    
    inline ::System::Data::SchemaSerializationMode NewDataSet::SchemaSerializationMode::get() {
        return this->_schemaSerializationMode;
    }
    inline System::Void NewDataSet::SchemaSerializationMode::set(::System::Data::SchemaSerializationMode value) {
        this->_schemaSerializationMode = __identifier(value);
    }
    
    inline ::System::Data::DataTableCollection^  NewDataSet::Tables::get() {
        return __super::Tables;
    }
    
    inline ::System::Data::DataRelationCollection^  NewDataSet::Relations::get() {
        return __super::Relations;
    }
    
    inline ::System::Void NewDataSet::InitializeDerivedDataSet() {
        this->BeginInit();
        this->InitClass();
        this->EndInit();
    }
    
    inline ::System::Data::DataSet^  NewDataSet::Clone() {
        schema::NewDataSet^  cln = (cli::safe_cast<schema::NewDataSet^  >(__super::Clone()));
        cln->InitVars();
        cln->SchemaSerializationMode = this->SchemaSerializationMode;
        return cln;
    }
    
    inline ::System::Boolean NewDataSet::ShouldSerializeTables() {
        return false;
    }
    
    inline ::System::Boolean NewDataSet::ShouldSerializeRelations() {
        return false;
    }
    
    inline ::System::Void NewDataSet::ReadXmlSerializable(::System::Xml::XmlReader^  reader) {
        if (this->DetermineSchemaSerializationMode(reader) == ::System::Data::SchemaSerializationMode::IncludeSchema) {
            this->Reset();
            ::System::Data::DataSet^  ds = (gcnew ::System::Data::DataSet());
            ds->ReadXml(reader);
            if (ds->Tables[L"contact"] != nullptr) {
                __super::Tables->Add((gcnew schema::NewDataSet::contactDataTable(ds->Tables[L"contact"])));
            }
            if (ds->Tables[L"homeAddress"] != nullptr) {
                __super::Tables->Add((gcnew schema::NewDataSet::homeAddressDataTable(ds->Tables[L"homeAddress"])));
            }
            if (ds->Tables[L"workAddress"] != nullptr) {
                __super::Tables->Add((gcnew schema::NewDataSet::workAddressDataTable(ds->Tables[L"workAddress"])));
            }
            this->DataSetName = ds->DataSetName;
            this->Prefix = ds->Prefix;
            this->Namespace = ds->Namespace;
            this->Locale = ds->Locale;
            this->CaseSensitive = ds->CaseSensitive;
            this->EnforceConstraints = ds->EnforceConstraints;
            this->Merge(ds, false, ::System::Data::MissingSchemaAction::Add);
            this->InitVars();
        }
        else {
            this->ReadXml(reader);
            this->InitVars();
        }
    }
    
    inline ::System::Xml::Schema::XmlSchema^  NewDataSet::GetSchemaSerializable() {
        ::System::IO::MemoryStream^  stream = (gcnew ::System::IO::MemoryStream());
        this->WriteXmlSchema((gcnew ::System::Xml::XmlTextWriter(stream, nullptr)));
        stream->Position = 0;
        return ::System::Xml::Schema::XmlSchema::Read((gcnew ::System::Xml::XmlTextReader(stream)), nullptr);
    }
    
    inline ::System::Void NewDataSet::InitVars() {
        this->InitVars(true);
    }
    
    inline ::System::Void NewDataSet::InitVars(::System::Boolean initTable) {
        this->tablecontact = (cli::safe_cast<schema::NewDataSet::contactDataTable^  >(__super::Tables[L"contact"]));
        if (initTable == true) {
            if (this->tablecontact != nullptr) {
                this->tablecontact->InitVars();
            }
        }
        this->tablehomeAddress = (cli::safe_cast<schema::NewDataSet::homeAddressDataTable^  >(__super::Tables[L"homeAddress"]));
        if (initTable == true) {
            if (this->tablehomeAddress != nullptr) {
                this->tablehomeAddress->InitVars();
            }
        }
        this->tableworkAddress = (cli::safe_cast<schema::NewDataSet::workAddressDataTable^  >(__super::Tables[L"workAddress"]));
        if (initTable == true) {
            if (this->tableworkAddress != nullptr) {
                this->tableworkAddress->InitVars();
            }
        }
        this->relationcontact_homeAddress = this->Relations[L"contact_homeAddress"];
        this->relationcontact_workAddress = this->Relations[L"contact_workAddress"];
    }
    
    inline ::System::Void NewDataSet::InitClass() {
        this->DataSetName = L"NewDataSet";
        this->Prefix = L"";
        this->Locale = (gcnew ::System::Globalization::CultureInfo(L""));
        this->EnforceConstraints = true;
        this->SchemaSerializationMode = ::System::Data::SchemaSerializationMode::IncludeSchema;
        this->tablecontact = (gcnew schema::NewDataSet::contactDataTable());
        __super::Tables->Add(this->tablecontact);
        this->tablehomeAddress = (gcnew schema::NewDataSet::homeAddressDataTable());
        __super::Tables->Add(this->tablehomeAddress);
        this->tableworkAddress = (gcnew schema::NewDataSet::workAddressDataTable());
        __super::Tables->Add(this->tableworkAddress);
        ::System::Data::ForeignKeyConstraint^  fkc;
        fkc = (gcnew ::System::Data::ForeignKeyConstraint(L"contact_homeAddress", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tablecontact->contact_IdColumn}, 
            gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tablehomeAddress->contact_IdColumn}));
        this->tablehomeAddress->Constraints->Add(fkc);
        fkc->AcceptRejectRule = ::System::Data::AcceptRejectRule::None;
        fkc->DeleteRule = ::System::Data::Rule::Cascade;
        fkc->UpdateRule = ::System::Data::Rule::Cascade;
        fkc = (gcnew ::System::Data::ForeignKeyConstraint(L"contact_workAddress", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tablecontact->contact_IdColumn}, 
            gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableworkAddress->contact_IdColumn}));
        this->tableworkAddress->Constraints->Add(fkc);
        fkc->AcceptRejectRule = ::System::Data::AcceptRejectRule::None;
        fkc->DeleteRule = ::System::Data::Rule::Cascade;
        fkc->UpdateRule = ::System::Data::Rule::Cascade;
        this->relationcontact_homeAddress = (gcnew ::System::Data::DataRelation(L"contact_homeAddress", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tablecontact->contact_IdColumn}, 
            gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tablehomeAddress->contact_IdColumn}, false));
        this->relationcontact_homeAddress->Nested = true;
        this->Relations->Add(this->relationcontact_homeAddress);
        this->relationcontact_workAddress = (gcnew ::System::Data::DataRelation(L"contact_workAddress", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tablecontact->contact_IdColumn}, 
            gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->tableworkAddress->contact_IdColumn}, false));
        this->relationcontact_workAddress->Nested = true;
        this->Relations->Add(this->relationcontact_workAddress);
    }
    
    inline ::System::Boolean NewDataSet::ShouldSerializecontact() {
        return false;
    }
    
    inline ::System::Boolean NewDataSet::ShouldSerializehomeAddress() {
        return false;
    }
    
    inline ::System::Boolean NewDataSet::ShouldSerializeworkAddress() {
        return false;
    }
    
    inline ::System::Void NewDataSet::SchemaChanged(::System::Object^  sender, ::System::ComponentModel::CollectionChangeEventArgs^  e) {
        if (e->Action == ::System::ComponentModel::CollectionChangeAction::Remove) {
            this->InitVars();
        }
    }
    
    inline ::System::Xml::Schema::XmlSchemaComplexType^  NewDataSet::GetTypedDataSetSchema(::System::Xml::Schema::XmlSchemaSet^  xs) {
        schema::NewDataSet^  ds = (gcnew schema::NewDataSet());
        ::System::Xml::Schema::XmlSchemaComplexType^  type = (gcnew ::System::Xml::Schema::XmlSchemaComplexType());
        ::System::Xml::Schema::XmlSchemaSequence^  sequence = (gcnew ::System::Xml::Schema::XmlSchemaSequence());
        ::System::Xml::Schema::XmlSchemaAny^  any = (gcnew ::System::Xml::Schema::XmlSchemaAny());
        any->Namespace = ds->Namespace;
        sequence->Items->Add(any);
        type->Particle = sequence;
        ::System::Xml::Schema::XmlSchema^  dsSchema = ds->GetSchemaSerializable();
        if (xs->Contains(dsSchema->TargetNamespace)) {
            ::System::IO::MemoryStream^  s1 = (gcnew ::System::IO::MemoryStream());
            ::System::IO::MemoryStream^  s2 = (gcnew ::System::IO::MemoryStream());
            try {
                ::System::Xml::Schema::XmlSchema^  schema = nullptr;
                dsSchema->Write(s1);
                for (                ::System::Collections::IEnumerator^  schemas = xs->Schemas(dsSchema->TargetNamespace)->GetEnumerator(); schemas->MoveNext();                 ) {
                    schema = (cli::safe_cast<::System::Xml::Schema::XmlSchema^  >(schemas->Current));
                    s2->SetLength(0);
                    schema->Write(s2);
                    if (s1->Length == s2->Length) {
                        s1->Position = 0;
                        s2->Position = 0;
                        for (                        ; ((s1->Position != s1->Length) 
                                    && (s1->ReadByte() == s2->ReadByte()));                         ) {
                            ;
                        }
                        if (s1->Position == s1->Length) {
                            return type;
                        }
                    }
                }
            }
            finally {
                if (s1 != nullptr) {
                    s1->Close();
                }
                if (s2 != nullptr) {
                    s2->Close();
                }
            }
        }
        xs->Add(dsSchema);
        return type;
    }
    
    
    inline NewDataSet::contactDataTable::contactDataTable() {
        this->TableName = L"contact";
        this->BeginInit();
        this->InitClass();
        this->EndInit();
    }
    
    inline NewDataSet::contactDataTable::contactDataTable(::System::Data::DataTable^  table) {
        this->TableName = table->TableName;
        if (table->CaseSensitive != table->DataSet->CaseSensitive) {
            this->CaseSensitive = table->CaseSensitive;
        }
        if (table->Locale->ToString() != table->DataSet->Locale->ToString()) {
            this->Locale = table->Locale;
        }
        if (table->Namespace != table->DataSet->Namespace) {
            this->Namespace = table->Namespace;
        }
        this->Prefix = table->Prefix;
        this->MinimumCapacity = table->MinimumCapacity;
    }
    
    inline NewDataSet::contactDataTable::contactDataTable(::System::Runtime::Serialization::SerializationInfo^  info, ::System::Runtime::Serialization::StreamingContext context) : 
            ::System::Data::DataTable(info, context) {
        this->InitVars();
    }
    
    inline ::System::Data::DataColumn^  NewDataSet::contactDataTable::givenNameColumn::get() {
        return this->columngivenName;
    }
    
    inline ::System::Data::DataColumn^  NewDataSet::contactDataTable::familyNameColumn::get() {
        return this->columnfamilyName;
    }
    
    inline ::System::Data::DataColumn^  NewDataSet::contactDataTable::birthdateColumn::get() {
        return this->columnbirthdate;
    }
    
    inline ::System::Data::DataColumn^  NewDataSet::contactDataTable::contact_IdColumn::get() {
        return this->columncontact_Id;
    }
    
    inline ::System::Int32 NewDataSet::contactDataTable::Count::get() {
        return this->Rows->Count;
    }
    
    inline schema::NewDataSet::contactRow^  NewDataSet::contactDataTable::default::get(::System::Int32 index) {
        return (cli::safe_cast<schema::NewDataSet::contactRow^  >(this->Rows[index]));
    }
    
    inline ::System::Void NewDataSet::contactDataTable::AddcontactRow(schema::NewDataSet::contactRow^  row) {
        this->Rows->Add(row);
    }
    
    inline schema::NewDataSet::contactRow^  NewDataSet::contactDataTable::AddcontactRow(System::String^  givenName, System::String^  familyName, 
                System::DateTime birthdate) {
        schema::NewDataSet::contactRow^  rowcontactRow = (cli::safe_cast<schema::NewDataSet::contactRow^  >(this->NewRow()));
        cli::array< ::System::Object^  >^  columnValuesArray = gcnew cli::array< ::System::Object^  >(4) {givenName, familyName, 
            birthdate, nullptr};
        rowcontactRow->ItemArray = columnValuesArray;
        this->Rows->Add(rowcontactRow);
        return rowcontactRow;
    }
    
    inline ::System::Collections::IEnumerator^  NewDataSet::contactDataTable::GetEnumerator() {
        return this->Rows->GetEnumerator();
    }
    
    inline ::System::Data::DataTable^  NewDataSet::contactDataTable::Clone() {
        schema::NewDataSet::contactDataTable^  cln = (cli::safe_cast<schema::NewDataSet::contactDataTable^  >(__super::Clone()));
        cln->InitVars();
        return cln;
    }
    
    inline ::System::Data::DataTable^  NewDataSet::contactDataTable::CreateInstance() {
        return (gcnew schema::NewDataSet::contactDataTable());
    }
    
    inline ::System::Void NewDataSet::contactDataTable::InitVars() {
        this->columngivenName = __super::Columns[L"givenName"];
        this->columnfamilyName = __super::Columns[L"familyName"];
        this->columnbirthdate = __super::Columns[L"birthdate"];
        this->columncontact_Id = __super::Columns[L"contact_Id"];
    }
    
    inline ::System::Void NewDataSet::contactDataTable::InitClass() {
        this->columngivenName = (gcnew ::System::Data::DataColumn(L"givenName", ::System::String::typeid, nullptr, ::System::Data::MappingType::Element));
        __super::Columns->Add(this->columngivenName);
        this->columnfamilyName = (gcnew ::System::Data::DataColumn(L"familyName", ::System::String::typeid, nullptr, ::System::Data::MappingType::Element));
        __super::Columns->Add(this->columnfamilyName);
        this->columnbirthdate = (gcnew ::System::Data::DataColumn(L"birthdate", ::System::DateTime::typeid, nullptr, ::System::Data::MappingType::Element));
        __super::Columns->Add(this->columnbirthdate);
        this->columncontact_Id = (gcnew ::System::Data::DataColumn(L"contact_Id", ::System::Int32::typeid, nullptr, ::System::Data::MappingType::Hidden));
        __super::Columns->Add(this->columncontact_Id);
        this->Constraints->Add((gcnew ::System::Data::UniqueConstraint(L"Constraint1", gcnew cli::array< ::System::Data::DataColumn^  >(1) {this->columncontact_Id}, 
                true)));
        this->columngivenName->AllowDBNull = false;
        this->columnfamilyName->AllowDBNull = false;
        this->columncontact_Id->AutoIncrement = true;
        this->columncontact_Id->AllowDBNull = false;
        this->columncontact_Id->Unique = true;
    }
    
    inline schema::NewDataSet::contactRow^  NewDataSet::contactDataTable::NewcontactRow() {
        return (cli::safe_cast<schema::NewDataSet::contactRow^  >(this->NewRow()));
    }
    
    inline ::System::Data::DataRow^  NewDataSet::contactDataTable::NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) {
        return (gcnew schema::NewDataSet::contactRow(builder));
    }
    
    inline ::System::Type^  NewDataSet::contactDataTable::GetRowType() {
        return schema::NewDataSet::contactRow::typeid;
    }
    
    inline ::System::Void NewDataSet::contactDataTable::OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) {
        __super::OnRowChanged(e);
        {
            this->contactRowChanged(this, (gcnew schema::NewDataSet::contactRowChangeEvent((cli::safe_cast<schema::NewDataSet::contactRow^  >(e->Row)), 
                    e->Action)));
        }
    }
    
    inline ::System::Void NewDataSet::contactDataTable::OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) {
        __super::OnRowChanging(e);
        {
            this->contactRowChanging(this, (gcnew schema::NewDataSet::contactRowChangeEvent((cli::safe_cast<schema::NewDataSet::contactRow^  >(e->Row)), 
                    e->Action)));
        }
    }
    
    inline ::System::Void NewDataSet::contactDataTable::OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) {
        __super::OnRowDeleted(e);
        {
            this->contactRowDeleted(this, (gcnew schema::NewDataSet::contactRowChangeEvent((cli::safe_cast<schema::NewDataSet::contactRow^  >(e->Row)), 
                    e->Action)));
        }
    }
    
    inline ::System::Void NewDataSet::contactDataTable::OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) {
        __super::OnRowDeleting(e);
        {
            this->contactRowDeleting(this, (gcnew schema::NewDataSet::contactRowChangeEvent((cli::safe_cast<schema::NewDataSet::contactRow^  >(e->Row)), 
                    e->Action)));
        }
    }
    
    inline ::System::Void NewDataSet::contactDataTable::RemovecontactRow(schema::NewDataSet::contactRow^  row) {
        this->Rows->Remove(row);
    }
    
    inline ::System::Xml::Schema::XmlSchemaComplexType^  NewDataSet::contactDataTable::GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs) {
        ::System::Xml::Schema::XmlSchemaComplexType^  type = (gcnew ::System::Xml::Schema::XmlSchemaComplexType());
        ::System::Xml::Schema::XmlSchemaSequence^  sequence = (gcnew ::System::Xml::Schema::XmlSchemaSequence());
        schema::NewDataSet^  ds = (gcnew schema::NewDataSet());
        ::System::Xml::Schema::XmlSchemaAny^  any1 = (gcnew ::System::Xml::Schema::XmlSchemaAny());
        any1->Namespace = L"http://www.w3.org/2001/XMLSchema";
        any1->MinOccurs = ::System::Decimal(0);
        any1->MaxOccurs = ::System::Decimal::MaxValue;
        any1->ProcessContents = ::System::Xml::Schema::XmlSchemaContentProcessing::Lax;
        sequence->Items->Add(any1);
        ::System::Xml::Schema::XmlSchemaAny^  any2 = (gcnew ::System::Xml::Schema::XmlSchemaAny());
        any2->Namespace = L"urn:schemas-microsoft-com:xml-diffgram-v1";
        any2->MinOccurs = ::System::Decimal(1);
        any2->ProcessContents = ::System::Xml::Schema::XmlSchemaContentProcessing::Lax;
        sequence->Items->Add(any2);
        ::System::Xml::Schema::XmlSchemaAttribute^  attribute1 = (gcnew ::System::Xml::Schema::XmlSchemaAttribute());
        attribute1->Name = L"namespace";
        attribute1->FixedValue = ds->Namespace;
        type->Attributes->Add(attribute1);
        ::System::Xml::Schema::XmlSchemaAttribute^  attribute2 = (gcnew ::System::Xml::Schema::XmlSchemaAttribute());
        attribute2->Name = L"tableTypeName";
        attribute2->FixedValue = L"contactDataTable";
        type->Attributes->Add(attribute2);
        type->Particle = sequence;
        ::System::Xml::Schema::XmlSchema^  dsSchema = ds->GetSchemaSerializable();
        if (xs->Contains(dsSchema->TargetNamespace)) {
            ::System::IO::MemoryStream^  s1 = (gcnew ::System::IO::MemoryStream());
            ::System::IO::MemoryStream^  s2 = (gcnew ::System::IO::MemoryStream());
            try {
                ::System::Xml::Schema::XmlSchema^  schema = nullptr;
                dsSchema->Write(s1);
                for (                ::System::Collections::IEnumerator^  schemas = xs->Schemas(dsSchema->TargetNamespace)->GetEnumerator(); schemas->MoveNext();                 ) {
                    schema = (cli::safe_cast<::System::Xml::Schema::XmlSchema^  >(schemas->Current));
                    s2->SetLength(0);
                    schema->Write(s2);
                    if (s1->Length == s2->Length) {
                        s1->Position = 0;
                        s2->Position = 0;
                        for (                        ; ((s1->Position != s1->Length) 
                                    && (s1->ReadByte() == s2->ReadByte()));                         ) {
                            ;
                        }
                        if (s1->Position == s1->Length) {
                            return type;
                        }
                    }
                }
            }
            finally {
                if (s1 != nullptr) {
                    s1->Close();
                }
                if (s2 != nullptr) {
                    s2->Close();
                }
            }
        }
        xs->Add(dsSchema);
        return type;
    }
    
    
    inline NewDataSet::homeAddressDataTable::homeAddressDataTable() {
        this->TableName = L"homeAddress";
        this->BeginInit();
        this->InitClass();
        this->EndInit();
    }
    
    inline NewDataSet::homeAddressDataTable::homeAddressDataTable(::System::Data::DataTable^  table) {
        this->TableName = table->TableName;
        if (table->CaseSensitive != table->DataSet->CaseSensitive) {
            this->CaseSensitive = table->CaseSensitive;
        }
        if (table->Locale->ToString() != table->DataSet->Locale->ToString()) {
            this->Locale = table->Locale;
        }
        if (table->Namespace != table->DataSet->Namespace) {
            this->Namespace = table->Namespace;
        }
        this->Prefix = table->Prefix;
        this->MinimumCapacity = table->MinimumCapacity;
    }
    
    inline NewDataSet::homeAddressDataTable::homeAddressDataTable(::System::Runtime::Serialization::SerializationInfo^  info, 
                ::System::Runtime::Serialization::StreamingContext context) : 
            ::System::Data::DataTable(info, context) {
        this->InitVars();
    }
    
    inline ::System::Data::DataColumn^  NewDataSet::homeAddressDataTable::streetColumn::get() {
        return this->columnstreet;
    }
    
    inline ::System::Data::DataColumn^  NewDataSet::homeAddressDataTable::zipCodeColumn::get() {
        return this->columnzipCode;
    }
    
    inline ::System::Data::DataColumn^  NewDataSet::homeAddressDataTable::cityColumn::get() {
        return this->columncity;
    }
    
    inline ::System::Data::DataColumn^  NewDataSet::homeAddressDataTable::countryColumn::get() {
        return this->columncountry;
    }
    
    inline ::System::Data::DataColumn^  NewDataSet::homeAddressDataTable::contact_IdColumn::get() {
        return this->columncontact_Id;
    }
    
    inline ::System::Int32 NewDataSet::homeAddressDataTable::Count::get() {
        return this->Rows->Count;
    }
    
    inline schema::NewDataSet::homeAddressRow^  NewDataSet::homeAddressDataTable::default::get(::System::Int32 index) {
        return (cli::safe_cast<schema::NewDataSet::homeAddressRow^  >(this->Rows[index]));
    }
    
    inline ::System::Void NewDataSet::homeAddressDataTable::AddhomeAddressRow(schema::NewDataSet::homeAddressRow^  row) {
        this->Rows->Add(row);
    }
    
    inline schema::NewDataSet::homeAddressRow^  NewDataSet::homeAddressDataTable::AddhomeAddressRow(System::String^  street, 
                System::String^  zipCode, System::String^  city, System::String^  country, schema::NewDataSet::contactRow^  parentcontactRowBycontact_homeAddress) {
        schema::NewDataSet::homeAddressRow^  rowhomeAddressRow = (cli::safe_cast<schema::NewDataSet::homeAddressRow^  >(this->NewRow()));
        cli::array< ::System::Object^  >^  columnValuesArray = gcnew cli::array< ::System::Object^  >(5) {street, zipCode, city, 
            country, nullptr};
        if (parentcontactRowBycontact_homeAddress != nullptr) {
            columnValuesArray[4] = parentcontactRowBycontact_homeAddress[3];
        }
        rowhomeAddressRow->ItemArray = columnValuesArray;
        this->Rows->Add(rowhomeAddressRow);
        return rowhomeAddressRow;
    }
    
    inline ::System::Collections::IEnumerator^  NewDataSet::homeAddressDataTable::GetEnumerator() {
        return this->Rows->GetEnumerator();
    }
    
    inline ::System::Data::DataTable^  NewDataSet::homeAddressDataTable::Clone() {
        schema::NewDataSet::homeAddressDataTable^  cln = (cli::safe_cast<schema::NewDataSet::homeAddressDataTable^  >(__super::Clone()));
        cln->InitVars();
        return cln;
    }
    
    inline ::System::Data::DataTable^  NewDataSet::homeAddressDataTable::CreateInstance() {
        return (gcnew schema::NewDataSet::homeAddressDataTable());
    }
    
    inline ::System::Void NewDataSet::homeAddressDataTable::InitVars() {
        this->columnstreet = __super::Columns[L"street"];
        this->columnzipCode = __super::Columns[L"zipCode"];
        this->columncity = __super::Columns[L"city"];
        this->columncountry = __super::Columns[L"country"];
        this->columncontact_Id = __super::Columns[L"contact_Id"];
    }
    
    inline ::System::Void NewDataSet::homeAddressDataTable::InitClass() {
        this->columnstreet = (gcnew ::System::Data::DataColumn(L"street", ::System::String::typeid, nullptr, ::System::Data::MappingType::Element));
        __super::Columns->Add(this->columnstreet);
        this->columnzipCode = (gcnew ::System::Data::DataColumn(L"zipCode", ::System::String::typeid, nullptr, ::System::Data::MappingType::Element));
        __super::Columns->Add(this->columnzipCode);
        this->columncity = (gcnew ::System::Data::DataColumn(L"city", ::System::String::typeid, nullptr, ::System::Data::MappingType::Element));
        __super::Columns->Add(this->columncity);
        this->columncountry = (gcnew ::System::Data::DataColumn(L"country", ::System::String::typeid, nullptr, ::System::Data::MappingType::Element));
        __super::Columns->Add(this->columncountry);
        this->columncontact_Id = (gcnew ::System::Data::DataColumn(L"contact_Id", ::System::Int32::typeid, nullptr, ::System::Data::MappingType::Hidden));
        __super::Columns->Add(this->columncontact_Id);
        this->columnstreet->AllowDBNull = false;
        this->columnzipCode->AllowDBNull = false;
        this->columncity->AllowDBNull = false;
        this->columncountry->AllowDBNull = false;
    }
    
    inline schema::NewDataSet::homeAddressRow^  NewDataSet::homeAddressDataTable::NewhomeAddressRow() {
        return (cli::safe_cast<schema::NewDataSet::homeAddressRow^  >(this->NewRow()));
    }
    
    inline ::System::Data::DataRow^  NewDataSet::homeAddressDataTable::NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) {
        return (gcnew schema::NewDataSet::homeAddressRow(builder));
    }
    
    inline ::System::Type^  NewDataSet::homeAddressDataTable::GetRowType() {
        return schema::NewDataSet::homeAddressRow::typeid;
    }
    
    inline ::System::Void NewDataSet::homeAddressDataTable::OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) {
        __super::OnRowChanged(e);
        {
            this->homeAddressRowChanged(this, (gcnew schema::NewDataSet::homeAddressRowChangeEvent((cli::safe_cast<schema::NewDataSet::homeAddressRow^  >(e->Row)), 
                    e->Action)));
        }
    }
    
    inline ::System::Void NewDataSet::homeAddressDataTable::OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) {
        __super::OnRowChanging(e);
        {
            this->homeAddressRowChanging(this, (gcnew schema::NewDataSet::homeAddressRowChangeEvent((cli::safe_cast<schema::NewDataSet::homeAddressRow^  >(e->Row)), 
                    e->Action)));
        }
    }
    
    inline ::System::Void NewDataSet::homeAddressDataTable::OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) {
        __super::OnRowDeleted(e);
        {
            this->homeAddressRowDeleted(this, (gcnew schema::NewDataSet::homeAddressRowChangeEvent((cli::safe_cast<schema::NewDataSet::homeAddressRow^  >(e->Row)), 
                    e->Action)));
        }
    }
    
    inline ::System::Void NewDataSet::homeAddressDataTable::OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) {
        __super::OnRowDeleting(e);
        {
            this->homeAddressRowDeleting(this, (gcnew schema::NewDataSet::homeAddressRowChangeEvent((cli::safe_cast<schema::NewDataSet::homeAddressRow^  >(e->Row)), 
                    e->Action)));
        }
    }
    
    inline ::System::Void NewDataSet::homeAddressDataTable::RemovehomeAddressRow(schema::NewDataSet::homeAddressRow^  row) {
        this->Rows->Remove(row);
    }
    
    inline ::System::Xml::Schema::XmlSchemaComplexType^  NewDataSet::homeAddressDataTable::GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs) {
        ::System::Xml::Schema::XmlSchemaComplexType^  type = (gcnew ::System::Xml::Schema::XmlSchemaComplexType());
        ::System::Xml::Schema::XmlSchemaSequence^  sequence = (gcnew ::System::Xml::Schema::XmlSchemaSequence());
        schema::NewDataSet^  ds = (gcnew schema::NewDataSet());
        ::System::Xml::Schema::XmlSchemaAny^  any1 = (gcnew ::System::Xml::Schema::XmlSchemaAny());
        any1->Namespace = L"http://www.w3.org/2001/XMLSchema";
        any1->MinOccurs = ::System::Decimal(0);
        any1->MaxOccurs = ::System::Decimal::MaxValue;
        any1->ProcessContents = ::System::Xml::Schema::XmlSchemaContentProcessing::Lax;
        sequence->Items->Add(any1);
        ::System::Xml::Schema::XmlSchemaAny^  any2 = (gcnew ::System::Xml::Schema::XmlSchemaAny());
        any2->Namespace = L"urn:schemas-microsoft-com:xml-diffgram-v1";
        any2->MinOccurs = ::System::Decimal(1);
        any2->ProcessContents = ::System::Xml::Schema::XmlSchemaContentProcessing::Lax;
        sequence->Items->Add(any2);
        ::System::Xml::Schema::XmlSchemaAttribute^  attribute1 = (gcnew ::System::Xml::Schema::XmlSchemaAttribute());
        attribute1->Name = L"namespace";
        attribute1->FixedValue = ds->Namespace;
        type->Attributes->Add(attribute1);
        ::System::Xml::Schema::XmlSchemaAttribute^  attribute2 = (gcnew ::System::Xml::Schema::XmlSchemaAttribute());
        attribute2->Name = L"tableTypeName";
        attribute2->FixedValue = L"homeAddressDataTable";
        type->Attributes->Add(attribute2);
        type->Particle = sequence;
        ::System::Xml::Schema::XmlSchema^  dsSchema = ds->GetSchemaSerializable();
        if (xs->Contains(dsSchema->TargetNamespace)) {
            ::System::IO::MemoryStream^  s1 = (gcnew ::System::IO::MemoryStream());
            ::System::IO::MemoryStream^  s2 = (gcnew ::System::IO::MemoryStream());
            try {
                ::System::Xml::Schema::XmlSchema^  schema = nullptr;
                dsSchema->Write(s1);
                for (                ::System::Collections::IEnumerator^  schemas = xs->Schemas(dsSchema->TargetNamespace)->GetEnumerator(); schemas->MoveNext();                 ) {
                    schema = (cli::safe_cast<::System::Xml::Schema::XmlSchema^  >(schemas->Current));
                    s2->SetLength(0);
                    schema->Write(s2);
                    if (s1->Length == s2->Length) {
                        s1->Position = 0;
                        s2->Position = 0;
                        for (                        ; ((s1->Position != s1->Length) 
                                    && (s1->ReadByte() == s2->ReadByte()));                         ) {
                            ;
                        }
                        if (s1->Position == s1->Length) {
                            return type;
                        }
                    }
                }
            }
            finally {
                if (s1 != nullptr) {
                    s1->Close();
                }
                if (s2 != nullptr) {
                    s2->Close();
                }
            }
        }
        xs->Add(dsSchema);
        return type;
    }
    
    
    inline NewDataSet::workAddressDataTable::workAddressDataTable() {
        this->TableName = L"workAddress";
        this->BeginInit();
        this->InitClass();
        this->EndInit();
    }
    
    inline NewDataSet::workAddressDataTable::workAddressDataTable(::System::Data::DataTable^  table) {
        this->TableName = table->TableName;
        if (table->CaseSensitive != table->DataSet->CaseSensitive) {
            this->CaseSensitive = table->CaseSensitive;
        }
        if (table->Locale->ToString() != table->DataSet->Locale->ToString()) {
            this->Locale = table->Locale;
        }
        if (table->Namespace != table->DataSet->Namespace) {
            this->Namespace = table->Namespace;
        }
        this->Prefix = table->Prefix;
        this->MinimumCapacity = table->MinimumCapacity;
    }
    
    inline NewDataSet::workAddressDataTable::workAddressDataTable(::System::Runtime::Serialization::SerializationInfo^  info, 
                ::System::Runtime::Serialization::StreamingContext context) : 
            ::System::Data::DataTable(info, context) {
        this->InitVars();
    }
    
    inline ::System::Data::DataColumn^  NewDataSet::workAddressDataTable::streetColumn::get() {
        return this->columnstreet;
    }
    
    inline ::System::Data::DataColumn^  NewDataSet::workAddressDataTable::zipCodeColumn::get() {
        return this->columnzipCode;
    }
    
    inline ::System::Data::DataColumn^  NewDataSet::workAddressDataTable::cityColumn::get() {
        return this->columncity;
    }
    
    inline ::System::Data::DataColumn^  NewDataSet::workAddressDataTable::countryColumn::get() {
        return this->columncountry;
    }
    
    inline ::System::Data::DataColumn^  NewDataSet::workAddressDataTable::contact_IdColumn::get() {
        return this->columncontact_Id;
    }
    
    inline ::System::Int32 NewDataSet::workAddressDataTable::Count::get() {
        return this->Rows->Count;
    }
    
    inline schema::NewDataSet::workAddressRow^  NewDataSet::workAddressDataTable::default::get(::System::Int32 index) {
        return (cli::safe_cast<schema::NewDataSet::workAddressRow^  >(this->Rows[index]));
    }
    
    inline ::System::Void NewDataSet::workAddressDataTable::AddworkAddressRow(schema::NewDataSet::workAddressRow^  row) {
        this->Rows->Add(row);
    }
    
    inline schema::NewDataSet::workAddressRow^  NewDataSet::workAddressDataTable::AddworkAddressRow(System::String^  street, 
                System::String^  zipCode, System::String^  city, System::String^  country, schema::NewDataSet::contactRow^  parentcontactRowBycontact_workAddress) {
        schema::NewDataSet::workAddressRow^  rowworkAddressRow = (cli::safe_cast<schema::NewDataSet::workAddressRow^  >(this->NewRow()));
        cli::array< ::System::Object^  >^  columnValuesArray = gcnew cli::array< ::System::Object^  >(5) {street, zipCode, city, 
            country, nullptr};
        if (parentcontactRowBycontact_workAddress != nullptr) {
            columnValuesArray[4] = parentcontactRowBycontact_workAddress[3];
        }
        rowworkAddressRow->ItemArray = columnValuesArray;
        this->Rows->Add(rowworkAddressRow);
        return rowworkAddressRow;
    }
    
    inline ::System::Collections::IEnumerator^  NewDataSet::workAddressDataTable::GetEnumerator() {
        return this->Rows->GetEnumerator();
    }
    
    inline ::System::Data::DataTable^  NewDataSet::workAddressDataTable::Clone() {
        schema::NewDataSet::workAddressDataTable^  cln = (cli::safe_cast<schema::NewDataSet::workAddressDataTable^  >(__super::Clone()));
        cln->InitVars();
        return cln;
    }
    
    inline ::System::Data::DataTable^  NewDataSet::workAddressDataTable::CreateInstance() {
        return (gcnew schema::NewDataSet::workAddressDataTable());
    }
    
    inline ::System::Void NewDataSet::workAddressDataTable::InitVars() {
        this->columnstreet = __super::Columns[L"street"];
        this->columnzipCode = __super::Columns[L"zipCode"];
        this->columncity = __super::Columns[L"city"];
        this->columncountry = __super::Columns[L"country"];
        this->columncontact_Id = __super::Columns[L"contact_Id"];
    }
    
    inline ::System::Void NewDataSet::workAddressDataTable::InitClass() {
        this->columnstreet = (gcnew ::System::Data::DataColumn(L"street", ::System::String::typeid, nullptr, ::System::Data::MappingType::Element));
        __super::Columns->Add(this->columnstreet);
        this->columnzipCode = (gcnew ::System::Data::DataColumn(L"zipCode", ::System::String::typeid, nullptr, ::System::Data::MappingType::Element));
        __super::Columns->Add(this->columnzipCode);
        this->columncity = (gcnew ::System::Data::DataColumn(L"city", ::System::String::typeid, nullptr, ::System::Data::MappingType::Element));
        __super::Columns->Add(this->columncity);
        this->columncountry = (gcnew ::System::Data::DataColumn(L"country", ::System::String::typeid, nullptr, ::System::Data::MappingType::Element));
        __super::Columns->Add(this->columncountry);
        this->columncontact_Id = (gcnew ::System::Data::DataColumn(L"contact_Id", ::System::Int32::typeid, nullptr, ::System::Data::MappingType::Hidden));
        __super::Columns->Add(this->columncontact_Id);
        this->columnstreet->AllowDBNull = false;
        this->columnzipCode->AllowDBNull = false;
        this->columncity->AllowDBNull = false;
        this->columncountry->AllowDBNull = false;
    }
    
    inline schema::NewDataSet::workAddressRow^  NewDataSet::workAddressDataTable::NewworkAddressRow() {
        return (cli::safe_cast<schema::NewDataSet::workAddressRow^  >(this->NewRow()));
    }
    
    inline ::System::Data::DataRow^  NewDataSet::workAddressDataTable::NewRowFromBuilder(::System::Data::DataRowBuilder^  builder) {
        return (gcnew schema::NewDataSet::workAddressRow(builder));
    }
    
    inline ::System::Type^  NewDataSet::workAddressDataTable::GetRowType() {
        return schema::NewDataSet::workAddressRow::typeid;
    }
    
    inline ::System::Void NewDataSet::workAddressDataTable::OnRowChanged(::System::Data::DataRowChangeEventArgs^  e) {
        __super::OnRowChanged(e);
        {
            this->workAddressRowChanged(this, (gcnew schema::NewDataSet::workAddressRowChangeEvent((cli::safe_cast<schema::NewDataSet::workAddressRow^  >(e->Row)), 
                    e->Action)));
        }
    }
    
    inline ::System::Void NewDataSet::workAddressDataTable::OnRowChanging(::System::Data::DataRowChangeEventArgs^  e) {
        __super::OnRowChanging(e);
        {
            this->workAddressRowChanging(this, (gcnew schema::NewDataSet::workAddressRowChangeEvent((cli::safe_cast<schema::NewDataSet::workAddressRow^  >(e->Row)), 
                    e->Action)));
        }
    }
    
    inline ::System::Void NewDataSet::workAddressDataTable::OnRowDeleted(::System::Data::DataRowChangeEventArgs^  e) {
        __super::OnRowDeleted(e);
        {
            this->workAddressRowDeleted(this, (gcnew schema::NewDataSet::workAddressRowChangeEvent((cli::safe_cast<schema::NewDataSet::workAddressRow^  >(e->Row)), 
                    e->Action)));
        }
    }
    
    inline ::System::Void NewDataSet::workAddressDataTable::OnRowDeleting(::System::Data::DataRowChangeEventArgs^  e) {
        __super::OnRowDeleting(e);
        {
            this->workAddressRowDeleting(this, (gcnew schema::NewDataSet::workAddressRowChangeEvent((cli::safe_cast<schema::NewDataSet::workAddressRow^  >(e->Row)), 
                    e->Action)));
        }
    }
    
    inline ::System::Void NewDataSet::workAddressDataTable::RemoveworkAddressRow(schema::NewDataSet::workAddressRow^  row) {
        this->Rows->Remove(row);
    }
    
    inline ::System::Xml::Schema::XmlSchemaComplexType^  NewDataSet::workAddressDataTable::GetTypedTableSchema(::System::Xml::Schema::XmlSchemaSet^  xs) {
        ::System::Xml::Schema::XmlSchemaComplexType^  type = (gcnew ::System::Xml::Schema::XmlSchemaComplexType());
        ::System::Xml::Schema::XmlSchemaSequence^  sequence = (gcnew ::System::Xml::Schema::XmlSchemaSequence());
        schema::NewDataSet^  ds = (gcnew schema::NewDataSet());
        ::System::Xml::Schema::XmlSchemaAny^  any1 = (gcnew ::System::Xml::Schema::XmlSchemaAny());
        any1->Namespace = L"http://www.w3.org/2001/XMLSchema";
        any1->MinOccurs = ::System::Decimal(0);
        any1->MaxOccurs = ::System::Decimal::MaxValue;
        any1->ProcessContents = ::System::Xml::Schema::XmlSchemaContentProcessing::Lax;
        sequence->Items->Add(any1);
        ::System::Xml::Schema::XmlSchemaAny^  any2 = (gcnew ::System::Xml::Schema::XmlSchemaAny());
        any2->Namespace = L"urn:schemas-microsoft-com:xml-diffgram-v1";
        any2->MinOccurs = ::System::Decimal(1);
        any2->ProcessContents = ::System::Xml::Schema::XmlSchemaContentProcessing::Lax;
        sequence->Items->Add(any2);
        ::System::Xml::Schema::XmlSchemaAttribute^  attribute1 = (gcnew ::System::Xml::Schema::XmlSchemaAttribute());
        attribute1->Name = L"namespace";
        attribute1->FixedValue = ds->Namespace;
        type->Attributes->Add(attribute1);
        ::System::Xml::Schema::XmlSchemaAttribute^  attribute2 = (gcnew ::System::Xml::Schema::XmlSchemaAttribute());
        attribute2->Name = L"tableTypeName";
        attribute2->FixedValue = L"workAddressDataTable";
        type->Attributes->Add(attribute2);
        type->Particle = sequence;
        ::System::Xml::Schema::XmlSchema^  dsSchema = ds->GetSchemaSerializable();
        if (xs->Contains(dsSchema->TargetNamespace)) {
            ::System::IO::MemoryStream^  s1 = (gcnew ::System::IO::MemoryStream());
            ::System::IO::MemoryStream^  s2 = (gcnew ::System::IO::MemoryStream());
            try {
                ::System::Xml::Schema::XmlSchema^  schema = nullptr;
                dsSchema->Write(s1);
                for (                ::System::Collections::IEnumerator^  schemas = xs->Schemas(dsSchema->TargetNamespace)->GetEnumerator(); schemas->MoveNext();                 ) {
                    schema = (cli::safe_cast<::System::Xml::Schema::XmlSchema^  >(schemas->Current));
                    s2->SetLength(0);
                    schema->Write(s2);
                    if (s1->Length == s2->Length) {
                        s1->Position = 0;
                        s2->Position = 0;
                        for (                        ; ((s1->Position != s1->Length) 
                                    && (s1->ReadByte() == s2->ReadByte()));                         ) {
                            ;
                        }
                        if (s1->Position == s1->Length) {
                            return type;
                        }
                    }
                }
            }
            finally {
                if (s1 != nullptr) {
                    s1->Close();
                }
                if (s2 != nullptr) {
                    s2->Close();
                }
            }
        }
        xs->Add(dsSchema);
        return type;
    }
    
    
    inline NewDataSet::contactRow::contactRow(::System::Data::DataRowBuilder^  rb) : 
            ::System::Data::DataRow(rb) {
        this->tablecontact = (cli::safe_cast<schema::NewDataSet::contactDataTable^  >(this->Table));
    }
    
    inline System::String^  NewDataSet::contactRow::givenName::get() {
        return (cli::safe_cast<::System::String^  >(this[this->tablecontact->givenNameColumn]));
    }
    inline System::Void NewDataSet::contactRow::givenName::set(System::String^  value) {
        this[this->tablecontact->givenNameColumn] = value;
    }
    
    inline System::String^  NewDataSet::contactRow::familyName::get() {
        return (cli::safe_cast<::System::String^  >(this[this->tablecontact->familyNameColumn]));
    }
    inline System::Void NewDataSet::contactRow::familyName::set(System::String^  value) {
        this[this->tablecontact->familyNameColumn] = value;
    }
    
    inline System::DateTime NewDataSet::contactRow::birthdate::get() {
        try {
            return (cli::safe_cast<::System::DateTime >(this[this->tablecontact->birthdateColumn]));
        }
        catch (::System::InvalidCastException^ e) {
            throw (gcnew ::System::Data::StrongTypingException(L"表“contact”中列“birthdate”的值为 DBNull。", e));
        }
    }
    inline System::Void NewDataSet::contactRow::birthdate::set(System::DateTime value) {
        this[this->tablecontact->birthdateColumn] = value;
    }
    
    inline System::Int32 NewDataSet::contactRow::contact_Id::get() {
        return (cli::safe_cast<::System::Int32 >(this[this->tablecontact->contact_IdColumn]));
    }
    inline System::Void NewDataSet::contactRow::contact_Id::set(System::Int32 value) {
        this[this->tablecontact->contact_IdColumn] = value;
    }
    
    inline ::System::Boolean NewDataSet::contactRow::IsbirthdateNull() {
        return this->IsNull(this->tablecontact->birthdateColumn);
    }
    
    inline ::System::Void NewDataSet::contactRow::SetbirthdateNull() {
        this[this->tablecontact->birthdateColumn] = ::System::Convert::DBNull;
    }
    
    inline cli::array< schema::NewDataSet::homeAddressRow^  >^  NewDataSet::contactRow::GethomeAddressRows() {
        if (this->Table->ChildRelations[L"contact_homeAddress"] == nullptr) {
            return gcnew cli::array< schema::NewDataSet::homeAddressRow^  >(0);
        }
        else {
            return (cli::safe_cast<cli::array< schema::NewDataSet::homeAddressRow^  >^  >(__super::GetChildRows(this->Table->ChildRelations[L"contact_homeAddress"])));
        }
    }
    
    inline cli::array< schema::NewDataSet::workAddressRow^  >^  NewDataSet::contactRow::GetworkAddressRows() {
        if (this->Table->ChildRelations[L"contact_workAddress"] == nullptr) {
            return gcnew cli::array< schema::NewDataSet::workAddressRow^  >(0);
        }
        else {
            return (cli::safe_cast<cli::array< schema::NewDataSet::workAddressRow^  >^  >(__super::GetChildRows(this->Table->ChildRelations[L"contact_workAddress"])));
        }
    }
    
    
    inline NewDataSet::homeAddressRow::homeAddressRow(::System::Data::DataRowBuilder^  rb) : 
            ::System::Data::DataRow(rb) {
        this->tablehomeAddress = (cli::safe_cast<schema::NewDataSet::homeAddressDataTable^  >(this->Table));
    }
    
    inline System::String^  NewDataSet::homeAddressRow::street::get() {
        return (cli::safe_cast<::System::String^  >(this[this->tablehomeAddress->streetColumn]));
    }
    inline System::Void NewDataSet::homeAddressRow::street::set(System::String^  value) {
        this[this->tablehomeAddress->streetColumn] = value;
    }
    
    inline System::String^  NewDataSet::homeAddressRow::zipCode::get() {
        return (cli::safe_cast<::System::String^  >(this[this->tablehomeAddress->zipCodeColumn]));
    }
    inline System::Void NewDataSet::homeAddressRow::zipCode::set(System::String^  value) {
        this[this->tablehomeAddress->zipCodeColumn] = value;
    }
    
    inline System::String^  NewDataSet::homeAddressRow::city::get() {
        return (cli::safe_cast<::System::String^  >(this[this->tablehomeAddress->cityColumn]));
    }
    inline System::Void NewDataSet::homeAddressRow::city::set(System::String^  value) {
        this[this->tablehomeAddress->cityColumn] = value;
    }
    
    inline System::String^  NewDataSet::homeAddressRow::country::get() {
        return (cli::safe_cast<::System::String^  >(this[this->tablehomeAddress->countryColumn]));
    }
    inline System::Void NewDataSet::homeAddressRow::country::set(System::String^  value) {
        this[this->tablehomeAddress->countryColumn] = value;
    }
    
    inline System::Int32 NewDataSet::homeAddressRow::contact_Id::get() {
        try {
            return (cli::safe_cast<::System::Int32 >(this[this->tablehomeAddress->contact_IdColumn]));
        }
        catch (::System::InvalidCastException^ e) {
            throw (gcnew ::System::Data::StrongTypingException(L"表“homeAddress”中列“contact_Id”的值为 DBNull。", e));
        }
    }
    inline System::Void NewDataSet::homeAddressRow::contact_Id::set(System::Int32 value) {
        this[this->tablehomeAddress->contact_IdColumn] = value;
    }
    
    inline schema::NewDataSet::contactRow^  NewDataSet::homeAddressRow::contactRow::get() {
        return (cli::safe_cast<schema::NewDataSet::contactRow^  >(this->GetParentRow(this->Table->ParentRelations[L"contact_homeAddress"])));
    }
    inline System::Void NewDataSet::homeAddressRow::contactRow::set(schema::NewDataSet::contactRow^  value) {
        this->SetParentRow(value, this->Table->ParentRelations[L"contact_homeAddress"]);
    }
    
    inline ::System::Boolean NewDataSet::homeAddressRow::Iscontact_IdNull() {
        return this->IsNull(this->tablehomeAddress->contact_IdColumn);
    }
    
    inline ::System::Void NewDataSet::homeAddressRow::Setcontact_IdNull() {
        this[this->tablehomeAddress->contact_IdColumn] = ::System::Convert::DBNull;
    }
    
    
    inline NewDataSet::workAddressRow::workAddressRow(::System::Data::DataRowBuilder^  rb) : 
            ::System::Data::DataRow(rb) {
        this->tableworkAddress = (cli::safe_cast<schema::NewDataSet::workAddressDataTable^  >(this->Table));
    }
    
    inline System::String^  NewDataSet::workAddressRow::street::get() {
        return (cli::safe_cast<::System::String^  >(this[this->tableworkAddress->streetColumn]));
    }
    inline System::Void NewDataSet::workAddressRow::street::set(System::String^  value) {
        this[this->tableworkAddress->streetColumn] = value;
    }
    
    inline System::String^  NewDataSet::workAddressRow::zipCode::get() {
        return (cli::safe_cast<::System::String^  >(this[this->tableworkAddress->zipCodeColumn]));
    }
    inline System::Void NewDataSet::workAddressRow::zipCode::set(System::String^  value) {
        this[this->tableworkAddress->zipCodeColumn] = value;
    }
    
    inline System::String^  NewDataSet::workAddressRow::city::get() {
        return (cli::safe_cast<::System::String^  >(this[this->tableworkAddress->cityColumn]));
    }
    inline System::Void NewDataSet::workAddressRow::city::set(System::String^  value) {
        this[this->tableworkAddress->cityColumn] = value;
    }
    
    inline System::String^  NewDataSet::workAddressRow::country::get() {
        return (cli::safe_cast<::System::String^  >(this[this->tableworkAddress->countryColumn]));
    }
    inline System::Void NewDataSet::workAddressRow::country::set(System::String^  value) {
        this[this->tableworkAddress->countryColumn] = value;
    }
    
    inline System::Int32 NewDataSet::workAddressRow::contact_Id::get() {
        try {
            return (cli::safe_cast<::System::Int32 >(this[this->tableworkAddress->contact_IdColumn]));
        }
        catch (::System::InvalidCastException^ e) {
            throw (gcnew ::System::Data::StrongTypingException(L"表“workAddress”中列“contact_Id”的值为 DBNull。", e));
        }
    }
    inline System::Void NewDataSet::workAddressRow::contact_Id::set(System::Int32 value) {
        this[this->tableworkAddress->contact_IdColumn] = value;
    }
    
    inline schema::NewDataSet::contactRow^  NewDataSet::workAddressRow::contactRow::get() {
        return (cli::safe_cast<schema::NewDataSet::contactRow^  >(this->GetParentRow(this->Table->ParentRelations[L"contact_workAddress"])));
    }
    inline System::Void NewDataSet::workAddressRow::contactRow::set(schema::NewDataSet::contactRow^  value) {
        this->SetParentRow(value, this->Table->ParentRelations[L"contact_workAddress"]);
    }
    
    inline ::System::Boolean NewDataSet::workAddressRow::Iscontact_IdNull() {
        return this->IsNull(this->tableworkAddress->contact_IdColumn);
    }
    
    inline ::System::Void NewDataSet::workAddressRow::Setcontact_IdNull() {
        this[this->tableworkAddress->contact_IdColumn] = ::System::Convert::DBNull;
    }
    
    
    inline NewDataSet::contactRowChangeEvent::contactRowChangeEvent(schema::NewDataSet::contactRow^  row, ::System::Data::DataRowAction action) {
        this->eventRow = row;
        this->eventAction = action;
    }
    
    inline schema::NewDataSet::contactRow^  NewDataSet::contactRowChangeEvent::Row::get() {
        return this->eventRow;
    }
    
    inline ::System::Data::DataRowAction NewDataSet::contactRowChangeEvent::Action::get() {
        return this->eventAction;
    }
    
    
    inline NewDataSet::homeAddressRowChangeEvent::homeAddressRowChangeEvent(schema::NewDataSet::homeAddressRow^  row, ::System::Data::DataRowAction action) {
        this->eventRow = row;
        this->eventAction = action;
    }
    
    inline schema::NewDataSet::homeAddressRow^  NewDataSet::homeAddressRowChangeEvent::Row::get() {
        return this->eventRow;
    }
    
    inline ::System::Data::DataRowAction NewDataSet::homeAddressRowChangeEvent::Action::get() {
        return this->eventAction;
    }
    
    
    inline NewDataSet::workAddressRowChangeEvent::workAddressRowChangeEvent(schema::NewDataSet::workAddressRow^  row, ::System::Data::DataRowAction action) {
        this->eventRow = row;
        this->eventAction = action;
    }
    
    inline schema::NewDataSet::workAddressRow^  NewDataSet::workAddressRowChangeEvent::Row::get() {
        return this->eventRow;
    }
    
    inline ::System::Data::DataRowAction NewDataSet::workAddressRowChangeEvent::Action::get() {
        return this->eventAction;
    }
}
