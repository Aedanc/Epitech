package epitech.fortev_g.todolist;

import android.content.Intent;
import android.database.Cursor;
import android.os.Debug;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.EditText;
import android.widget.ListView;

import org.apache.commons.io.FileUtils;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;

public class ListActivity extends AppCompatActivity {

    private ArrayList<String> items;
    private TodoAdaptater itemsAdapter;
    private ListView lvItems;
    private SQLiteHelper database;
    private Cursor data;
    ArrayList<String> title = new ArrayList<String>();
    ArrayList<String> content = new ArrayList<String>();
    ArrayList<String> date = new ArrayList<String>();
    ArrayList<String> time = new ArrayList<String>();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_list);
        lvItems = (ListView) findViewById(R.id.lvItems);
        items = new ArrayList<String>();
        database = new SQLiteHelper(this);
        data = database.getData();
        while (data.moveToNext())
        {
            title.add(data.getString(1));
            content.add(data.getString(2));
            date.add(data.getString(3));
            time.add(data.getString(4));
        }

        itemsAdapter = new TodoAdaptater(this, title,content,date,time);
        lvItems.setAdapter(itemsAdapter);
        setupListViewListener();
    }

    private void setupListViewListener() {
        lvItems.setOnItemLongClickListener(
                new AdapterView.OnItemLongClickListener() {
                    @Override
                    public boolean onItemLongClick(AdapterView<?> adapter,
                                                   View item, int pos, long id) {
                        database.deleteName((int)id);
                        Log.i("nice", item);
                        itemsAdapter.notifyDataSetChanged();
                        return true;
                    }

                });
    }


    public void onAddItem(View v) {
        startActivity(new Intent(ListActivity.this, CreateActivity.class));
        data = database.getData();
        title.clear();
        content.clear();
        date.clear();
        time.clear();
        while (data.moveToNext())
        {
            title.add(data.getString(1));
            content.add(data.getString(2));
            date.add(data.getString(3));
            time.add(data.getString(4));
        }

        itemsAdapter = new TodoAdaptater(this, title,content,date,time);
        lvItems.setAdapter(itemsAdapter);
    }
}
