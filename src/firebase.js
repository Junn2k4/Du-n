import { initializeApp } from "firebase/app";
import { getDatabase } from "firebase/database";
import { getAuth } from "firebase/auth";

const firebaseConfig = {
  apiKey: "AIzaSyANuOc4feLOxOLN0oSi5Xgzo1tgeMwvmxc",
  authDomain: "baidoxe-002.firebaseapp.com",
  databaseURL: "https://baidoxe-002-default-rtdb.asia-southeast1.firebasedatabase.app",
  projectId: "baidoxe-002",
  storageBucket: "baidoxe-002.firebasestorage.app",
  messagingSenderId: "583863059424",
  appId: "1:583863059424:web:7e1af905a7fb1dc192a185",
  measurementId: "G-ZBKNYT3QGN"
};

const app = initializeApp(firebaseConfig);
const db = getDatabase(app);
const auth = getAuth(app);

export { db, auth };
