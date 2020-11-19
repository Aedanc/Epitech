package epitech.fortev_g.todolist;

import android.app.Activity;
import android.support.annotation.NonNull;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.TextView;

import java.util.ArrayList;

/**
 * Created by fortev_g on 04/02/2018.
 */

public class TodoAdaptater extends ArrayAdapter<String> {
    private final Activity context;
    private final ArrayList<String> title;
    private final ArrayList<String> content;
    private final ArrayList<String> date;
    private final ArrayList<String> time;

    public TodoAdaptater(Activity context,
                         ArrayList<String> title, ArrayList<String> content, ArrayList<String> date, ArrayList<String> time) {
        super(context, R.layout.todo_adaptater, title);
        this.context = context;
        this.title = title;
        this.content = content;
        this.date = date;
        this.time = time;
    }

    @Override
    public View getView(int position, View view, @NonNull ViewGroup parent) {
        LayoutInflater inflater = context.getLayoutInflater();
        View rowView= inflater.inflate(R.layout.todo_adaptater, null, true);
        TextView txtTitle = rowView.findViewById(R.id.TodoTitle);
        TextView txtContent = rowView.findViewById(R.id.TodoContent);
        TextView txtdate = rowView.findViewById(R.id.TodoDate);
        TextView txttime = rowView.findViewById(R.id.TodoTime);

        txtTitle.setText(title.get(position));
        txtContent.setText(content.get(position));
        txtdate.setText(date.get(position));
        txttime.setText(time.get(position));
        return rowView;
    }
}
