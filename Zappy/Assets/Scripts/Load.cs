using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class Load : MonoBehaviour {
    float go;
    public float time;
    // Use this for initialization
    public string levelName;
    AsyncOperation async;

    public void StartLoading()
    {
        StartCoroutine("load");
    }

    IEnumerator load()
    {
        Debug.LogWarning("ASYNC LOAD STARTED - " +
           "DO NOT EXIT PLAY MODE UNTIL SCENE LOADS... UNITY WILL CRASH");
        async = SceneManager.LoadSceneAsync(levelName);
        async.allowSceneActivation = false;
        yield return async;
    }

    void Start ()
    {
        go = Time.time;
        StartLoading();
    }
	void Update () {
        if ((Time.time - go) > time)
        {
            async.allowSceneActivation = true;
        }
	}
}
