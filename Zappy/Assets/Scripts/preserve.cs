using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class preserve : MonoBehaviour {
	public void preservevalue() {
		DontDestroyOnLoad(transform.gameObject);
	}
}
